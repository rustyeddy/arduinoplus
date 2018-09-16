package main

import (
	"time"
	"flag"
	"gobot.io/x/gobot"
	"gobot.io/x/gobot/api"
	"gobot.io/x/gobot/drivers/gpio"
	"gobot.io/x/gobot/platforms/firmata"
)

var (
	serialPorts [2]string
)

func init() {
	flag.StringVar(&serialPorts[0], "serial-port", "/dev/tty.usbmodem1421", "Set the serial port")
	flag.StringVar(&serialPorts[1], "serial-port2", "/dev/tty.usbmodem1411", "Set the serial port")
}

func main() {
	flag.Parse()
	foo()
}

func foo() {
	master := gobot.NewMaster()

	a := api.NewAPI(master)
	a.Start()

	fa0 := firmata.NewAdaptor(serialPorts[0])

	rled := gpio.NewLedDriver(fa0, "9")
	gled := gpio.NewLedDriver(fa0, "11")
	button := gpio.NewButtonDriver(fa0, "7")

	fa1 := firmata.NewAdaptor(serialPorts[1])
	led := gpio.NewLedDriver(fa1, "13")

	work := func() {
		gobot.Every(1*time.Second, func() {
			gled.Toggle()
			rled.Toggle()
			led.Toggle()
		})
	}

	robot := gobot.NewRobot("bot",
		[]gobot.Connection{fa0},
		[]gobot.Connection{fa1},
		[]gobot.Device{gled},
		[]gobot.Device{rled},
		[]gobot.Device{button},
		[]gobot.Device{led},
		work,
	)
	master.AddRobot(robot)
	master.Start()
	fmt.Printf("FA0 %+v\n", fa0)
}

package main

type ConfigMap map[string]string

var (
	logConfig = &ConfigMap{
		"format": "json",
		"output": "stderr",
		"level": "warn",
	}
	debugConfig = &COnfigMap{
		"format": "text",
		"output": "stdout",
		"level": "debug"
	}
)


func (cm *ConfigMap) Get(name string) (s string, exists bool) {
	if val, e := cm[name]; e {
		return val, e
	}
	return "", false
}

func (cm *ConfigMap) Exists(name string) bool {
	_, e := cm.Get(name)
	return e
}

func (cm *ConfigMap) Val(name string) string {
	if v, e := cm.Get(name); e {
		return v
	}
	return ""
}

func (cm *ConfigMap) Set(name string, val string) {
	cm[name] = val
}

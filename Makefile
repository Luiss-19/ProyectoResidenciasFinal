main: compile

compile:
	sdcc --use-non-free -mpic16 -p18f45k50 src/main.c
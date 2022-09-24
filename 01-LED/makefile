AC := arduino-cli.exe
FQBN := arduino:avr:uno
SERIAL := COM4

SRC := *.ino

.PHONY: all compile upload monitor

all: monitor

compile: $(SRC)
	$(AC) compile --fqbn $(FQBN) $^

upload: compile
	$(AC) upload -p $(SERIAL) --fqbn $(FQBN) $(SRC)

monitor: upload
	$(AC) monitor -p $(SERIAL)

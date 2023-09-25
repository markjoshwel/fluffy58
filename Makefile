# adapted from https://medium.com/@patrick.elmquist/separate-keymap-repo-for-qmk-136ff5a419bd

BOOTLOADER ?= avrdude
BUILD_DIR ?= $(shell pwd)
JOBS ?= 1

TARGET = lily58
USER = fluffy58

.PHONY: prebuild postbuild _build build preflash _flashn _flashl _flashr flash flashl flashr clean

build: prebuild _build postbuild

prebuild:
	# init and update submodules
	git submodule update --init --recursive

	# remove old symlink
	rm -rf qmk_firmware/keyboards/$(TARGET)/keymaps/$(USER)

	# add new symlink
	mkdir -p qmk_firmware/keyboards/$(TARGET)/keymaps/
	ln -s $(shell pwd)/$(TARGET)/ qmk_firmware/keyboards/$(TARGET)/keymaps/$(USER)

	# lint
	# cd qmk_firmware; qmk lint -km $(USER) -kb $(TARGET)

postbuild:
	rm -rf qmk_firmware/.build
	rm -rf qmk_firmware/keyboards/$(TARGET)/keymaps/$(USER)
	rm -rf $(BUILD_DIR)/obj_*

_build:
	make BUILD_DIR=$(BUILD_DIR) --jobs=$(JOBS) -C qmk_firmware $(TARGET):$(USER)

preflash: prebuild _build

_flashn:
	cd qmk_firmware; qmk flash -kb $(TARGET)/rev1 -km $(USER)

_flashl:
	cd qmk_firmware; qmk flash -kb $(TARGET)/rev1 -km $(USER) -bl $(BOOTLOADER)-split-left

_flashr:
	cd qmk_firmware; qmk flash -kb $(TARGET)/rev1 -km $(USER) -kb $(TARGET) -bl $(BOOTLOADER)-split-right

flash: clean prebuild _flashn postbuild
flashl: clean prebuild _flashl postbuild
flashr: clean prebuild _flashr postbuild

clean: postbuild
	rm -rf obj_*
	rm -f *.elf
	rm -f *.map
	rm -f *.hex

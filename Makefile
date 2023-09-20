# adapted from https://medium.com/@patrick.elmquist/separate-keymap-repo-for-qmk-136ff5a419bd

BUILD_DIR ?= $(shell pwd)
JOBS ?= 1

TARGET = lily58
USER = fluffy58

.PHONY: build
build:
	# init and update submodules
	git submodule update --init --recursive

	# remove old symlink
	rm -rf qmk_firmware/keyboards/$(TARGET)/keymaps/$(USER)

	# add new symlink
	mkdir -p qmk_firmware/keyboards/$(TARGET)/keymaps/
	ln -s $(shell pwd)/$(TARGET)/ qmk_firmware/keyboards/$(TARGET)/keymaps/$(USER)

	# lint
	# cd qmk_firmware; qmk lint -km $(USER) -kb $(TARGET)

	# build
	make BUILD_DIR=$(BUILD_DIR) -j1 -C qmk_firmware $(TARGET):$(USER)

	# cleanup
	rm -rf qmk_firmware/keyboards/$(TARGET)/keymaps/$(USER)
	rm -rf $(BUILD_DIR)/obj_*

clean:
	rm -rf obj_*
	rm -f *.elf
	rm -f *.map
	rm -f *.hex

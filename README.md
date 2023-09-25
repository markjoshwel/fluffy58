# fluffy58 v2

an approachable 60%-like QMK keymap for the [Lily58 Pro RE](https://github.com/kissetfall/Lily58-Pro-RE)

- [using the keymap](#using-the-keymap)
  - [layout](#layout)
    - [default (qwerty) layer](#default-qwerty-layer)
    - [lower layer](#lower-layer)
    - [adjust layer](#adjust-layer)
  - [encoder controls](#encoder-controls)
- [make it yours](#make-it-yours)
- [building](#building)
- [flashing](#flashing)
  - [using QMK Toolbox](#using-qmk-toolbox)
  - [from the command-line](#from-the-command-line)

## using the keymap

there are three layers: default (qwerty), lower and adjust.  
see [layout](#layout) for a visual representation of the keymap.

1. **default (qwerty) layer**  

   this is the default layer, which is active when no other layer is active.

   to access the other layers, you need to hold down the `LOWER` key.

2. **lower layer**

   gives acess to variations of keys unable to fit in the default layer.

   - numbers 1-8 turn into function keys 1-8.
   - number 9 turns into `{`. (using `(` as a mnemonic - remember the bracket!)
   - number 0 turns into `}`. (using `)` as a mnemonic - remember the bracket!)
   - backspace turns into delete.
   - key `/` turns into `\`. (using `/` as a mnemonic - remember the line!)

   access the layer by holding the `LOWER` key.

3. **adjust layer**

   gives access to all function keys, arrow keys, `MENU` key, caps lock, mouse control,
   controller reset and numpad.

   access the layer by holding `LOWER` + `ADJUST`. (the `ADJUST` key is only accessible
   in the lower layer.)

   you can toggle the layer on by double tapping `ADJUST`, while holding down `LOWER`.
   if toggled, you can exit the layer by pressing `ESC`.

### layout

#### default (qwerty) layer

  ```text
  ,-----------------------------------------.                    ,-----------------------------------------.
  |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
  |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  =   |
  |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  -   |
  |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
  |LCTRL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |  '  |
  `-----------------------------------------/       /     \      \-----------------------------------------'
                    |LOWER | LGUI | LAlt | /Space  /       \Space \  |Enter | RAlt |LOWER |
                    |      |      |      |/       /         \      \ |      |      |      |
                    `----------------------------'           '------''--------------------'
  ```

#### lower layer

  ```text
  ,-----------------------------------------.                    ,-----------------------------------------.
  | ESC  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  {   |  }   | DEL  |
  |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  |      |      |      |      |      |      |                    |      |      |      |      |      |      |
  |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
  |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
  |      |      |      |      |      |      |-------|    |-------|      |      |      |      |  \   |      |
  `-----------------------------------------/       /     \      \-----------------------------------------'
                    |      |      |      | /ADJUST /       \ADJUST\  |      |      |      |
                    |      |      |      |/       /         \      \ |      |      |      |
                    `----------------------------'           '------''--------------------'
  ```

#### adjust layer

  ```text
  ,-----------------------------------------.                    ,-----------------------------------------.
  |QWERTY|  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  |      |
  |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  | Tab  | F11  | F12  |  M1  | MUp  |  M2  |                    |      |  Up  |      |   7  |   8  |   9  |
  |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  |CapsLk|LShift|      |MLeft |Mdown |MRight|-------.    ,-------| Left | Down |Right |   4  |   5  |   6  |
  |------+------+------+------+------+------| Reset |    | Reset |------+------+------+------+------+------|
  |LCTRL |      |      |MAccl0|MAccl1|MAccl3|-------|    |-------|      |      |      |   1  |   2  |   3  |
  `-----------------------------------------/       /     \      \-----------------------------------------'
                    | MENU | LGUI | LAlt | /       /       \      \  |Enter | RAlt |   0  |
                    |      |      |      |/       /         \      \ |      |      |      |
                    `----------------------------'           '------''--------------------'
  ```

### encoder controls

- **left encoder**
  - clockwise rotation: scroll wheel down
  - counter-clockwise rotation: scroll wheel up
  - press (adjust layer): reset

- **right encoder**
  - clockwise rotation: volume up
  - counter-clockwise rotation: volume down
  - press (adjust layer): reset

## make it yours

this keymap is very bare bones, because that's all I need. there's no userspace here.

want underglow? rgb? look around for a config you like and add their respective sections
to `config.h`, `keymap.c` and `rules.mk`.

## building

you will need [qmk-cli](https://docs.qmk.fm/#/newbs_getting_started?id=set-up-your-environment).

1. **clone the repository if you haven't yet:**

   ```shell
   git clone https://github.com/markjoshwel/fluffy58.git --recurse-submodules
   ```

2. **build!**

   ```shell
   make build
   ```

   nix/devbox users can use devbox to build the keymap:

   ```shell
   devbox run make
   ```

## flashing

> [!WARNING]
> while one of the sides is powered, at any point do not plug in or out the TRRS cable!
> doing so might cause an irreversible electric fault.

either [build](#building) a .hex file yourself or grab one from the
[releases page](https://github.com/markjoshwel/fluffy58/releases).

flash one side at a time, separately and NOT connected to each other.

for more information on flashing in general, see <https://docs.qmk.fm/#/newbs_flashing>.

### using QMK Toolbox

1. open [QMK Toolbox](https://github.com/qmk/qmk_toolbox)., select the .hex file you want
   to flash and enable auto-flash.

   ![QMK Toolbox](./imgs/toolbox-0.png)

2. get your Lily58 into dfu/bootloader mode:

   - flashing from the fluffy58 keymap:

     press `Reset` by holding down `LOWER` +`ADJUST`, and pressing down any of your two
     rotary encoders.

   - flashing for the first time/from another keymap without a `Reset` or similar key:

     on your Lily58, short the RESET holes on the pcb. you can use a pair of tweezers or
     something similar to do this.

     however, if the RESET holes are not accessible, you can directly short the RESET and
     GND pins on your controller. see your controller's pinouts for this.

     your controller should now enter DFU mode, shortly after which QMK Toolbox will
     recognise your controller and flash the hex file.

3. et voilà! you're done. repeat for the other side.

### from the command-line

> [!NOTE]  
> windows users: use the [QMK WSL2 distro](https://qmk.github.io/qmk_distro_wsl/).

1. clone the repository:

   ```shell
   git clone https://github.com/markjoshwel/fluffy58.git --recurse-submodules
   ```

2. flash the left side:

   ```shell
   make BOOTLOADER=avrdude flashl
   ```

3. flash the right side:

   ```shell
   make BOOTLOADER=avrdude flashr
   ```

notes:

- change `BOOTLOADER=avrdude` if necessary, however is not needed and can be omitted if
  using `avrdude`.
- `make flash` will not flash with a `-bl $(BOOTLOADER)-split-left/right` argument
- optionally run `make clean` if you want to tidy up the repository

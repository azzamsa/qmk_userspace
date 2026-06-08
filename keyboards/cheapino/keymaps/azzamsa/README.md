# Cheapino keymap

```bash
$ cd qmk_firmware
$ git checkout cheapinov2
```

```bash
$ qmk compile --clean --keyboard cheapino --keymap azzamsa
$ qmk flash --clean --keyboard cheapino --keymap azzamsa

$ # press `media mod` key + `b` key (QK_BOOT) to accept the flash
# Hold the reset button while plugging in the keyboard, then place the `*.uf2` file inside the mounted directory.
```

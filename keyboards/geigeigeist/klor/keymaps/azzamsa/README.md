# KLOR keymap

```bash
$ cd qmk_firmware
$ git checkout master
```

```bash
$ qmk compile --clean --keyboard geigeigeist/klor --keymap azzamsa

$ qmk flash --clean --keyboard geigeigeist/klor --keymap azzamsa

$ # Activate `QK_BOOT` by pressing the top pinky key and the outermost left thumb key.
$ # Or short the `GND` and `RST` pin on the pro-micro board.
```

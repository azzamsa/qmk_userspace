# KLOR keymap

```bash
$ cd qmk_firmware
$ git checkout master
```

```bash
$ qmk compile --clean --keyboard geigeigeist/klor --keymap azzamsa

$ qmk flash --clean --keyboard geigeigeist/klor --keymap azzamsa --bootloader avrdude

$ # short the `GND` and `RST` pin on the pro-micro board
```

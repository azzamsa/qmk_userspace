# Dweeeeep keymap

```bash
$ git remote add fingerpunch https://github.com/sadekbaroudi/qmk_firmware.git
$ git fetch --all
$ git checkout develop_fingerpunch

$ qmk compile --clean --keyboard fingerpunch/dweeeeep --keymap azzamsa
$ qmk flash --clean --keyboard fingerpunch/dweeeeep --keymap azzamsa
```

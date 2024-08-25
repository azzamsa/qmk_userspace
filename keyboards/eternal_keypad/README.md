# Eternal Keyboard

## Flashing

```bash
# Check the code before flashing
$ qmk compile --clean --keyboard eternal_keypad --keymap azzamsa
$ qmk flash --clean --keyboard eternal_keypad --keymap azzamsa --bootloader avrdude
```

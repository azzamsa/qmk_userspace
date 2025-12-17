# Guide

## Setup

```bash
$ cd qmk_firmware
$ qmk setup --home $(pwd)

$ cd qmk_userspace
$ qmk config usek.overlay_dir=$(pwd)

$ # flash your favourite keyboard!
$ cd qmk_firmware
$ qmk compile --keyboard cheapino --keymap azzamsa
```

## Keymap Drawer

- Open [Keymap Drawer](https://keymap-drawer.streamlit.app/)
- Copy the `keymap-drawer.yml`
- Enable `dark_mode`.
- Remove the `footer_text`.
- Export: PNG, Resoultion Scale: 10

## Useful links

- [Configuring QMK | QMK Firmware](https://docs.qmk.fm/config_options)
- [Keycodes Overview | QMK Firmware](https://docs.qmk.fm/keycodes)
- [US ANSI Shifted Symbols | QMK Firmware](https://docs.qmk.fm/keycodes_us_ansi_shifted)

# QMK Userspace

Configurations for my keyboards.

## Layout

<div align="center">
<img src='https://github.com/user-attachments/assets/5b06afdf-b475-4add-8ff3-879051bf7fde' width=250px />
</div>

## Setup

```bash
$ cd qmk_firmware
$ qmk setup --home $(pwd)

$ cd qmk_userspace
$ qmk config user.overlay_dir=$(pwd)

$ # flash your favourite keyboard!
$ qmk compile --keyboard cheapino --keymap azzamsa
```

## History

| Period                   | Duration         | Alpha      | Symbol           | Keyboard             | Features               |
| ------------------------ | ---------------- | ---------- | ---------------- | -------------------- | ---------------------- |
| 20 Jun 2021 – 2 Aug 2021 | 2 months         | Qwerty     | Custom           | Sofle 58             | n.a                    |
| 3 Aug 2021 – Jan 2025    | 3 years 5 months | Colemak-DH | Miryoku          | Sofle 36             | n.a                    |
| Jan 2025 – May 2025      | 5 months         | Colemak-DH | Miryoku inspired | KLOR 36, Cheapino 36 | sm_td                  |
| May 2025 – Jun 2025      | 1 month          | Colemak-DH | Seniply inspired | KLOR 34              | n.a                    |
| Jun 2025 - 24 Nov 2025   | 6 months         | Colemak-DH | Seniply inspired | Cheapino 36          | chordal hold, flow tap |
| 24 Nov 2025 - today      | ongoing          | Colemak-DH | Sunaku inspired  | Cheapino 36          | chordal hold, flow tap |

## Keymap Inspirations

- Alpha: [Colemak-DH](https://colemakmods.github.io/mod-dh/)
- Symbol: [Sunaku's Keymap](https://github.com/sunaku/glove80-keymaps)

## Keyboards

- [josefadamcik/SofleKeyboard](https://github.com/josefadamcik/SofleKeyboard), June 2021
- [pashutk/chocofi](https://github.com/pashutk/chocofi), May 2023
- [sadekbaroudi/Dweeeeep](https://github.com/sadekbaroudi/sweep36), Sept 2023
- [duckyb/eternal-keypad](https://github.com/duckyb/eternal-keypad), Sept 2023
- [GEIGEIGEIST/KLOR](https://github.com/GEIGEIGEIST/KLOR), Sept 2023
- [tompi/cheapino](https://github.com/tompi/cheapino), Nov 2024

## References

- [Configuring QMK | QMK Firmware](https://docs.qmk.fm/config_options)
- [Keycodes Overview | QMK Firmware](https://docs.qmk.fm/keycodes)
- [US ANSI Shifted Symbols | QMK Firmware](https://docs.qmk.fm/keycodes_us_ansi_shifted)

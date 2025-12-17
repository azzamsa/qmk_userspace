# QMK Userspace

Configurations for my keyboards.

## Layout

I use Hands Down™ Promethium as base. For details, see [LAYOUT.md](LAYOUT.md)

Symbol:

<div align="center">
<img width="250" alt="Symbol" src="https://github.com/user-attachments/assets/17eb30fb-a424-4276-aff7-65217796fb04" />
</div>

Numbers:

<div align="center">
<img width="250" alt="Numbers" src="https://github.com/user-attachments/assets/8911ce28-b861-4e51-a3a6-4c850fa7c5e1" />
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

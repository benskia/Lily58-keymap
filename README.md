# Lily58 QMK QWERTY Keymap

This layout focuses on general use with programming as a close second.

**Note:** Before flashing, confirm handedness in config.h (default=LEFT)

## Movements

The movement cluster (arrows, pgup, home, etc) is layered on and around HJKL, a
la Vim.

[ LOWER + ]

* Left          : H
* Down          : J
* Up            : K
* Right         : L

* Home          : Y
* PgDn          : U
* PgUp          : I
* End           : O

## Brackets

Left and right bracket-handedness correspond to LOWER and UPPER layers
respectively. Angle brackets are placed to favor creating comparison operators
and arrows - RABK shares base layout key as a bonus.

[ LOWER + ]

* [             : S
* {             : D
* (             : F
* <             : X

[ UPPER + ]

* ]             : L
* }             : K
* )             : J
* >             : >

## Expressions and Arrows

Colon and slash share base layout keys.

[ LOWER + ]

* !             : A
* *             : Z
* -             : C
* =             : V
* +             : B

[ UPPER + ]

* :             : :
* /             : /
* -             : <
* =             : M
* +             : N

## Extrakeys

[ UPPER + ]

* Play/Pause    : W
* Prev Track    : E
* Next Track    : R

* Mute          : S
* Volume Dn     : D
* Volume Up     : F

* Printscreen   : X
* Brightness Dn : C
* Brightness Up : V

# sketch_aug10b

An Arduino sketch that controls a 4-servo walking robot using a timed gait sequence.

## Overview

This project drives a small robot with four servo motors to produce a walking motion. A `ServoMaster` class manages all four servos, handling per-servo angle offsets, smooth angle interpolation (via an `update()` loop), and immediate positioning. The main `loop()` uses a frame counter and a repeating 170-step cycle to choreograph the leg movements.

### Key components

| File | Description |
|---|---|
| `sketch_aug10b.ino` | Main Arduino sketch — current walking algorithm |
| `old_walking_algithan.h` | Earlier version of the `ServoMaster` class and walking algorithm (kept for reference) |

## Hardware

- **Microcontroller:** Arduino (any board with digital PWM pins)
- **Servos:** 4× standard hobby servo motors
- **Servo pins (current sketch):** 9, 12, 10, 11

## How it works

1. **Setup** — All four servos are initialised to 90° (neutral), then eased to a starting stance (servos 0 & 3 at 120°, servos 1 & 2 at 60°).
2. **Loop** — Each iteration the frame counter increments and `servoMaster.update()` is called, which moves every servo one step (up to 1.25°) toward its target angle.
3. **Gait sequence** — At specific frame offsets within the 170-frame cycle, target angles are updated to produce a coordinated four-legged walking gait.

### Angle correction

Each servo has a calibration offset stored in `offsetServo[]`. The output angle is also scaled by a factor of `0.55` centred on 90°, which compensates for the mechanical range of the servo horns.

## Getting started

1. Open `sketch_aug10b.ino` in the [Arduino IDE](https://www.arduino.cc/en/software).
2. Connect the four servos to pins **9**, **10**, **11**, and **12**.
3. Select your board and port, then upload.

## File history

`old_walking_algithan.h` contains an earlier iteration of the servo controller that used per-servo integer variables instead of arrays and a different offset/mirroring scheme. It is preserved for reference and is not included by the main sketch.

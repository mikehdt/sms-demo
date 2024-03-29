# Sega Master System Demo

I'm making a mess learning stuff about coding for the Sega Master System. Being helped along by some much more clever people who _actually_ know what they're doing.

Some basic settings exist for VSCode. I'm currently building on Windows, but as I do cross-platform I may aim to make it also as Mac-friendly as possible (some third-party tooling notwithstanding).

## Goals

-   [x] Have C remote debugging with Emulicious
-   [x] Draw a picture to the screen
-   [x] Animate the picture with some scrolling
-   [x] Make the picture a bit fancier with V interrupt individual scrolls
-   [x] Add some sprites
-   [x] Animate the sprites
-   [x] Add a second example file
-   [x] Animate the palette in from black
-   [x] Have a scene manager to swap between effects
-   [x] Have more than one bank, to learn about bank switching
-   [x] Improve the responsiveness of button presses
-   [x] Figure out why the plasma effect is _cursed_
-   [ ] Improve the build pipeline (makefile)
-   [ ] Investigate making the build pipeline cross-platform (as much as is possible)
-   [ ] Investigate whether the `z88dk` SDCC patch is viable with Emulicious debugging as an alternative
-   [ ] Animate palettes between each other (not just from black)
-   [ ] Figure out a nicer way to integrate inline z80 assembly with VScode...
-   [ ] Improve the core structure with more single-purpose functions
-   [ ] Add music?

## Controls

Press the `1` button to cycle through the various scenes (some more computationally-heavy scenes might need a bit of an extra kick to move on...)

## Dependencies

It uses [devkitSMS](https://github.com/sverx/devkitSMS) as a basis for doing all its fancy stuff.

Code is compiled with [SDCC](http://sdcc.sourceforge.net/) `4.3.0` . The SDCC `4.2.0` release changed a lot of things. The C debugging is working again between Emulicious / VSCode! Although I've also learned that if a lot of local variables exist (eg. nested loops) then the outer counters are unreliable as they may reference Z80 registers that are being used for other things.

The [bmp2tile](https://github.com/maxim-zhao/bmp2tile) project is included here for compiling assets, but I might move it to be an external dep later. For cross-platform support later, the [png2tile](https://github.com/yuv422/png2tile) looks like a great starting point.

I've added the [STMcomp plugin](https://github.com/sverx/STMcomp) by sverx to the `bmp2tile` utility here, needed for using STM compressed tilemaps. It's nifty.

Using VScode, make sure to install the [Emulicious Debugger](https://marketplace.visualstudio.com/items?itemName=emulicious.emulicious-debugger).

## Building

I need to expand this bit, but the basics is that once the external deps are in place, you can use VScode `Ctrl+Shift+P` > `Run Task` to first run `Compile Assets`.

Then you can use the `F5` key to automatically compile and attach the Emulicious Debugger to VScode and Emulicious, or use `Run Task` again to `Build (Debug)` and run it manually.

I plan to make this better at some stage. I'm just figuring things out for now, really.

## Thanks

-   The [SMS Power Forums](https://www.smspower.org/forums) have many super helpful and smart people
-   The [Gotris](https://gitlab.com/1985Alternativo/gotris) project by kusfo has been invaluable for learning. I've shamelessly borrowed some techniques, and am indebted to the knowledge contained therein and its author
-   The [devkitSMS](https://github.com/sverx/devkitSMS) project by sverx made setting up easy, and it makes getting started with the Sega Master System fast and fun
-   The [bmp2tile](https://github.com/maxim-zhao/bmp2tile) project by Maxim makes getting assets into a format suitable for the SMS really easy
-   The [Emulicious](https://emulicious.net/) emulator has fantastic support for SDCC's debug output being bridged across to VScode, making working with the SMS so much easier, and Calindro has been very helpful
-   My friends bananaboy, sh0ck, null, and cTrix, with whom we made a little SMS demo for the [Syntax Demoparty](https://syntaxparty.org/) in 2021. The experience making the art for it, even though simple, inspired me to learn about coding for the SMS so we can push the art even _further_... next time?

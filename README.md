# interra1n
[![GitHub Release](https://img.shields.io/github/v/release/checkra1n-Team/interra1n?include_prereleases)](https://github.com/checkra1n-Team/interra1n/releases)
[![GitHub Downloads (all assets, all releases)](https://img.shields.io/github/downloads/checkra1n-Team/interra1n/total)](https://github.com/checkra1n-Team/interra1n/releases)
[![GitHub License](https://img.shields.io/github/license/checkra1n-Team/interra1n?color=%23C96FAD)](https://github.com/checkra1n-Team/interra1n/blob/main/LICENSE)

Interra1n is a community fork of [palera1n](https://github.com/palera1n/palera1n), the checkm8-based jailbreak for A8–A11 and T2 devices. It follows palera1n's supported-device and platform requirements while adding fork-specific changes. Read the [upstream palera1n guide](https://palera.in/) for background on the jailbreak and its device requirements.

Jailbreak for A8 through A11, T2 devices, on iOS/iPadOS/tvOS 15.0, bridgeOS 5.0 and higher.




| ![Screenshot of macOS Terminal.app](assets/image-1.png)	| 
|:--:												| 
| A screenshot of palera1n being used in a Terminal | 

## Device Support

<!--- Mobile --->

| iPhone(s)                 | iPad(s)                        		| iPod(s)   					| Apple TV(s) 					|
|-							|-										|-								|-								|
| iPhone 6s                 | iPad mini 4							| iPod Touch (7th generation)	| Apple TV HD                 	|
| iPhone 6s Plus            | iPad (5th generation)					|								| Apple TV 4K (1st generation)	|
| iPhone SE (2016)          | iPad (6th generation)					|								|								|
| iPhone 7                  | iPad (7th generation)					|								|								|
| iPhone 7 Plus             | iPad Pro (9.7")						|								|								|
| iPhone 8                  | iPad Pro (12.9") (1st generation)		|								|								|
| iPhone 8 Plus             | iPad Pro (10.5")						|								|								|
| iPhone X                  | iPad Pro (12.9") (2nd generation)		|								|								|
|                           | iPad Air 2		|								|								|


> Note that on `A11` (iPhone X, 8, 8 Plus), **you must disable your passcode while in the jailbroken state** (on iOS 16, you need to **reset your device** before proceeding with palera1n).

<!--- T2 --->
<details>
<summary>Apple T2 Device Support (click to expand)</summary>

| Apple T2              	|
|-							|
| Apple T2 iMac20,1         |
| Apple T2 iMac20,2         |
| 			              	|
| Apple T2 MacBookAir8,1    |
| Apple T2 MacBookAir8,2    |
| Apple T2 MacBookAir9,1    |
| 			              	|
| Apple T2 MacBookPro15,1   |
| Apple T2 MacBookPro15,2   |
| Apple T2 MacBookPro15,3   |
| Apple T2 MacBookPro15,4   |
| Apple T2 MacBookPro16,1   |
| Apple T2 MacBookPro16,2   |
| Apple T2 MacBookPro16,3   |
| Apple T2 MacBookPro16,4   |
| 			              	|
| Apple T2 iMacPro1,1       |
| Apple T2 Macmini8,1       |
| Apple T2 MacPro7,1        |
|			              	|
| iBridge2,11 (Unknown Mac) |
| iBridge2,13 (Unknown Mac) |



</details>


## Computer Requirements
1. **USB-A** cables are recommended to use, USB-C to may have issues with palera1n and getting into DFU mode.
> Due to USB-C cables having different accessory IDs, your device may not be able to be recognized when using USB-C due to not being able to assert to its USB voltage pin.

2. **Linux or macOS computer**
> AMD CPUs (not AMD Mobile) have an issue where it causes them to have a very low success rate with checkm8 exploit. It is not recommended that you use them with palera1n.

> USB-C port on Apple Silicon Macs *may* require manual unplugging and replugging of the lightning cable after checkm8 exploit. This problem may be solved by connecting via USB hub, though extensions can vary.

## Usage 
```
Usage: palera1n [-DEhgpvVdsSLRnPI] [-e boot arguments] [-k Pongo image] [-g background image] [-o overlay file] [-r ramdisk file] [-K KPF file] [-i checkra1n file]

	--version				Print version
	--force-revert				Remove jailbreak
	-d, --demote				Demote
	-D, --dfuhelper				Exit after entering DFU
	-e, --boot-args <boot arguments>	XNU boot arguments
	-E, --enter-recovery			Enter recovery mode
	-h, --help				Show this help
	-i, --override-checkra1n <file>		Override checkra1n
	-k, --override-pongo <file>		Override Pongo image
	-g, --pongo-background <image>	Set the PongoOS raindrop splash background (PNG, JPEG, BMP)
	-K, --override-kpf <file>		Override kernel patchfinder
	-L, --jbinit-log-to-file		Make jbinit log to /cores/jbinit.log (can be read from sandbox while jailbroken)
	-n, --exit-recovery			Exit recovery mode
	-I, --device-info			Print info about the connected device
	-o, --override-overlay <file>		Override overlay
	-p, --pongo-shell			Boots to PongoOS shell
	-P, --pongo-full			Boots to a PongoOS shell with default images already uploaded
	-r, --override-ramdisk <file>		Override ramdisk
	-R, --reboot-device			Reboot connected device in normal mode
	-s, --safe-mode				Enter safe mode
	-S, --no-colors				Disable colors on the command line
	-v, --debug-logging			Enable debug logging
		  This option can be repeated for extra verbosity.
	-V, --verbose-boot			Verbose boot

Environmental variables:
	TMPDIR		temporary diretory (path the built-in checkra1n will be extracted to)
```

### Custom PongoOS splash

Pass a PNG, JPEG, or BMP image with `--pongo-background` to replace the background behind the PongoOS raindrop during boot:

```sh
palera1n --pongo-background ./my-splash.png
```

The image is resized to a maximum of 1024 pixels per side and center-cropped to fit the connected display. It is sent to the device for that run and is not saved on the device. The framebuffer renderer scales it for all iPhone models supported by this fork. The image is applied after PongoOS connects over USB; use `--pongo-shell` to leave the device at the PongoOS shell with the custom splash. Pass the option again on later runs to reuse the same image. This option uses interra1n's bundled PongoOS image and cannot be combined with `--override-pongo`.

## Installing
See the [interra1n releases](https://github.com/checkra1n-Team/interra1n/releases) for builds. For jailbreak setup and device requirements, read the [upstream palera1n guide](https://palera.in/).

## Building from source

Clone this repository and run `make`. The build initializes the PongoOS source submodule and builds interra1n's patched PongoOS image before compiling the host tool. macOS builds require Xcode command line tools. Linux builds require `clang`, `ld64`, and `cctools-strip` in addition to the dependencies used by palera1n; see the [PongoOS build instructions](https://github.com/palera1n/PongoOS#building-on-linux).

## Disclaimers
We are **NOT** responsible for any data loss, or the result of a device being bricked. When using palera1n, the user should accept responsibility if anything happens to their device during the process.
- If your device is stuck in recovery, please run futurerestore `--exit-recovery`, or use `irecovery -n`, or `palera1n -n`.
- If you're unable to get out of recovery via these methods please restore with iTunes or Finder.
- palera1n **will not work** in VirtualBox, VMware or any virtual machine that doesn't support PCI passthrough.

## Troubleshooting
Make sure you're following the guides provided [here](https://palera.in), also when asking for support make sure you provide full details on your device, such as:
- iPhone/iPad/iPod/Apple TV
- iOS Version
- Passcode enabled?
- Verbose from palera1n (specifying `-Vv` within palera1n)
- Panic logs, if panicked then send latest `panic-full` log from your device.

Create an issue here: https://github.com/checkra1n-Team/interra1n/issues/new/choose

## Credits

Interra1n fork credit: **@xperia_remixes**.

The fork is based on palera1n. [Upstream palera1n credits](https://palera.in/) recognize the original project contributors.

See [third-party notices](THIRD_PARTY_NOTICES.md) for PongoOS and image decoder licensing.

If a credit is missing, please create an issue in this repository.

# FotoBox for Raspberry Pi, Linux and macOS [![Travis CI:build status](https://travis-ci.org/tomikais/fotobox.svg?branch=develop)](https://travis-ci.org/tomikais/fotobox) [![Slack:FotoBox](https://img.shields.io/badge/slack-FotoBox-blue.svg?logo=slack)](https://foto-box.slack.com/messages/CL3JQ1VJ8/)

FotoBox is a free open source multi platform application, that offers you the possibility to operate a photo booth (photobooth).

## features

* support a variety of different [DSLR camera models](http://www.gphoto.org/proj/libgphoto2/support.php)
* trigger photos directly or start a countdown by touching, clicking the screen, using soft-/hardware buttons, pressing keyboard shortcuts or using a presenter
* lightning fast and low-memory Linux / macOS customizable application

## Linux installation

Paste the commands in a terminal prompt.

1. update your operating system: `sudo apt-get update && sudo apt-get upgrade && sudo apt-get dist-upgrade`
2. download and install [Qt](https://www.qt.io): `sudo apt-get install qt5-default`
3. install [gPhoto2](http://gphoto.org) when you are using a DSLR camera
    * __recommended way__: use [gPhoto2 and libgphoto2 compiler and installer script](http://github.com/gonzalo/gphoto2-updater) to get latest version, make sure the default installed has been removed: `sudo apt-get purge gphoto2 libgphoto2-6`
    * use latest available gphoto2 provided from operating system: `sudo apt-get install gphoto2`
4. download latest __FotoBox__ version [here](https://github.com/tomikais/fotobox/releases) (according to your operating system)

### optional steps

* _Raspberry Pi_: [Setting up](https://projects.raspberrypi.org/en/projects/raspberry-pi-setting-up) your [Raspberry Pi Model >=2](https://www.raspberrypi.org/products/) with lates Raspbian version (Buster). If you are using the official [Camera Module V2](https://www.raspberrypi.org/products/camera-module-v2/) follow the [activate Raspberry Pi Camera](https://www.raspberrypi.org/documentation/usage/camera/) tutorial.
* _Disable the screen saver_: `sudo apt-get install xscreensaver`, run `xhost +localhost` from a local terminal session (not SSH) and reboot the system. After reboot you can launch the *'Screensaver'* application and select *'disable screen saver'* from the drop down.
* _Autostart_: open autostart file with `sudo nano /etc/xdg/lxsession/LXDE-pi/autostart` add this line `@/home/pi/Downloads/FotoBox` (__adjust path if necessary__) at the end of the file.
* _Using a button_: It's possible to connect a hardware button to the Raspberry Pi GPIO ([WiringPi](http://wiringpi.com)) pins to trigger the FotoBox. You can configure [dedicated pins](http://wiringpi.com/pins/) in the application or use the default ones:  
![Raspberry Pi 2 Model B default GPIO used by FotoBox](other/RaspPi_2B_default_GPIO.jpg)

## macOS installation

1. follow the short instruction to install [Homebrew - The missing package manager for macOS](https://brew.sh/)
2. use Homebrew to install gphoto2. Paste that in a macOS Terminal prompt: `brew install gphoto2`
3. download latest __FotoBox__ version [here](https://github.com/tomikais/fotobox/releases)

## keyboard shortcuts

| key                                                              | action            |
|------------------------------------------------------------------|-------------------|
| `N`, `Enter`, `Page Up/Down`, `Arrow Keys`, `Space`, `Backspace` | start FotoBox     |
| `P`, `S`, `E`                                                    | preference dialog |
| `Shift` + `Escape`, `Q`                                          | quit application  |

## Frequently Asked Questions

**Q:** I have misconfigured FotoBox and now it isn't working properly anymore?  
**A:** Start FotoBox application and press "Restore Defaults" button to load the default settings.

**Q:** Is my DSLR camera supported by FotoBox?  
**A:** Visit website [libgphoto2 supported cameras](http://www.gphoto.org/proj/libgphoto2/support.php) to check if your camera model is listed and supports _Image Capture_. Use [gPhoto2 and libgphoto2 compiler and installer script](http://github.com/gonzalo/gphoto2-updater) to get latest version and make sure the OS default one has been removed: `sudo apt-get purge gphoto2 libgphoto2-6`

**Q:** Where can I report FotoBox software bugs or suggest new features?  
**A:** [GitLab issue tracker](https://gitlab.com/tomikais/fotobox/issues)

**Q:** Where can I get FotoBox support?  
**A:** [German Raspberry Pi Forum](https://forum-raspberrypi.de/forum/thread/39672-fotobox-projekt-fuer-den-raspberry-pi-c-qt-wiringpi-gphoto2/) or official [Raspberry Pi Forum](https://www.raspberrypi.org/forums/viewtopic.php?t=218279) (english)

---

## development [![Doxygen:documentation](https://img.shields.io/badge/Doxygen-documentation-lightgrey.svg?logo=doxygen)](https://tomikais.github.io/fotobox/)

Follow the normal installation instructions and additionally install the development tools according to your operating system. Paste the commands in a terminal prompt.

### Linux (Debian, Raspbian, Ubuntu)

* install Linux development tools: `sudo apt-get install build-essential ccache`
* install Qt development tools: `sudo apt-get install qttools5-dev-tools qttools5-dev qtdeclarative5-dev qtcreator qt5-doc`
* install git with tools: `sudo apt-get install git git-doc git-gui gitk`
* _optional tools:_  `sudo apt-get install cmake doxygen doxygen-doc doxygen-gui graphviz`

### macOS

* install macOS development tools: `xcode-select --install`
* install Qt development tools: `brew install qt && brew link --force qt && brew cask install qt-creator`
* _optional tools:_ `brew install cmake && brew install doxygen`

### get source code

GitLab source code: `git clone --recursive git@gitlab.com:tomikais/fotobox.git` or `https://gitlab.com/tomikais/fotobox.git`

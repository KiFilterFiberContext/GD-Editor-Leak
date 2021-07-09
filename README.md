# Geometry Dash 2.2 Leak Editor 
This repository contains reverse engineered structures and reimplemented editor code needed to restore the editor in the 2019 Geometry Dash 2.2 leaks.

### Disclaimer
- I am not the owner of Geometry Dash nor am I affiliated with RobTop Games.  RobTop has publicly acknowledged the existence of the restoration and any action taken by him will be respected following publication.  
- The code has not been touched in various months and I claim no responsibility for actions you take with it
- I do not condone pirating or illegal distrbution of the game.  This repository merely documents my notes and analysis of the editor reimplementation.

## Details
Geometry Dash is a semi-platformer game published by RobTop Games in 2013.  It was initially released on iOS and Android, then published to Steam in 2014.  The game consists of the player controlling a square in a horizontal platformer along with multiple game modes, icons and more.  The most notable feature is the editor, which allows sharing user made levels onto the servers.

In the years since there have been multiple updates and several free games that have been published.  The three side games that have been published are: [World](https://play.google.com/store/apps/details?id=com.robtopx.geometrydashworld&hl=en_US&gl=US), [Meltdown](https://play.google.com/store/apps/details?id=com.robtopx.geometrydashmeltdown&hl=en_US&gl=US), and [SubZero](https://play.google.com/store/apps/details?id=com.robtopx.geometrydashsubzero&hl=en_US&gl=US).  The game also has a [lite](https://play.google.com/store/apps/details?id=com.robtopx.geometryjumplite&hl=en_US&gl=US) version which can also be downloaded for free.

The latest update to the game was 2.1, which was published in 2017.  In the multiple years that have passed since, the next update, 2.2, has not released (as of July 9th, 2021).  However, the side games do contain extra functionality leaked (whether intentional or not), however the latest dates back to 2017.

## The Leak
On December 5th, 2019, the Lite and Meltdown versions were [taken off the Play Store](https://twitter.com/RobTopGames/status/1202556326330675200?s=19) following an advertisement being present in the games.  They are restored five days later, however, extra functionality that includes new gamemodes and editor features were included in the restored versions.  The leak was confirmed by [Viprin](https://twitter.com/vipringd/status/1204878660282601473?s=20), a trusted associate of RobTop.  

The leak included many new features, yet some features were stripped from the release binaries before being published.  This included parts of the new multiplayer mode (dubbed Challenge Mode), the Map, and the revamped 2.2 editor.  Days following the leaked, [SMJS](https://www.youtube.com/channel/UClXb1w9vSL3Z0V-mUbudOnw) was able to patch the code to swap ship and swing copter gamemode transitions.  He was also responsible for developing the SubZero private server which had some of the new 2.2 features at the time.  

Desite attempts from collaborating members of the programming and reverse engineering community, hopes of restoring the editor was lost due to the daunting task of having to reverse engineer and accurately rewrite parts of the editor layer.  After a year, I decided to single-handindly reverse engineer the [editor](https://www.youtube.com/watch?v=JzAEiaySqTM). 

Initial reverse engineering was done by bindiffing the leaked lite binary against the 2017 SubZero and 2.0 binaries.  I tracked all modifications and proceeded to perform analysis on any changes made on member offsets and additions to the editor structure.  After support from various people from the community after providing assets, the editor was now functional.  It still lacked ful reimplementation, however due to it needing to be fully compatible with other editor routine, it can be considered as a near full recreation of the initialization routine.  Due to some missing textures and other additions, some modifications had to be done for compatibility.

At its current state, the reverse engineered structures are not fully documented.  They only contain the __BARE MINIMUM__ for the editor to function and **do not** contain more recent additions or structures since then.  Do not expect it to be stable as the leaks are incomplete and contain missing implementation details leading to frequent crashes without further modifications.  It also contains relevant code for supporting software breakpoints on ARM processors, however it is not designed to be very extensible due to the fact that I never intended to publish the project and has been left in an disorganized state. 

## History Credits
- [Geometry Dash Unofficial Wiki](https://geometry-dash.fandom.com/wiki/Update_2.2)

## License
- GPL v3

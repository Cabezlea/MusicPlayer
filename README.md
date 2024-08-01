# C++ Music Player

This project is a simple music player application developed in C++ using the Qt framework. It allows users to play, pause, and navigate through songs, as well as display album artwork and song metadata.

## Features

- **Play/Pause**: Basic playback controls to play and pause songs.
- **Song Navigation**: Navigate through a list of songs.
- **Album Artwork**: Display album art associated with the currently playing song.
- **Metadata Display**: Show song details such as title, artist, and album.

## How to Use

- **Start the Application**: Compile and run the `MusicPlayer` application.
- **Adding Songs**: Songs can be added to the player by placing them in the designated directory or loading them through the interface.
- **Playback Controls**: Use the play, pause, and skip buttons to control playback.

## Screenshots

Here is a screenshot of the Music Player application:

![image](https://github.com/Cabezlea/MusicPlayer/blob/main/Images/ForReadMe.png)


## File Structure

- **MainWindow.cpp**: Contains the main interface and logic for the player. This is the file that contains most of the functionality of the program, such as using QT for the User Interface, manages controls, and the audiofiles.

- **AudioPlayer.cpp**: Handles the core functionality of each button such as skip or rewind, works with the other libraries such as portaudio.
  
- **PlayerControls.cpp**: Manages the logic of each button, such as pause or resume.
  
- **Images/**: Directory containing image assets and other resources.

## Contribution

Contributions to this project are welcome! If you have suggestions or improvements, please fork the repository and submit a pull request with your changes. Ensure you test the changes locally before making a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- Thanks to the Qt community for providing comprehensive documentation and tools.
- Special thanks to developers and enthusiasts who contribute to open-source music libraries and tools.
- Inspired by classic music players and the desire to learn C++ and Qt framework.

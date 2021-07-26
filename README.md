[![LinkedIn][linkedin-shield]][linkedin-url]
<!--
[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]


[![Github][github-shield]][github.com/zoumson?tab=repositories]
[![Stack Overflow][stackoverflow-shield]][stackoverflow.com/users/11175375/adam]
[![Leetcode][leetcode-shield]][eetcode.com/Hard_Code/]
-->
## Command line parser using gnu, opencv, and boost
<img width="469" alt="parse" src="https://user-images.githubusercontent.com/38358621/127037754-bcaa022a-220d-4fcc-9117-75a84e47f91b.png">

<!-- TABLE OF CONTENTS -->
<details open="open">
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#file-structure">Files Structure</a>
      <ul>
        <li><a href="#folders">Folders</a></li>
        <li><a href="#entire-files-structure">Entire Files Structure</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgements">Acknowledgements</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

<!-- [![Product Name Screen Shot][product-screenshot]](https://example.com) -->

Many of the cpp programs that you’ll write will end up as binaries that need to be run from a command prompt. Any nontrivial command line should support a collection of basic features:

* Parsing of command-line arguments

* Generation of error messages in response to incorrect inputs

* Help for all the available options

It’s tedious and error-prone to code all of this manually for every program you write. This repository provides the Command Sample code in three different aspects, namely gnu, opencv, and boost, which simplifies the command line configuration by letting you declare your command-line options in one place and by deriving all of the above functionality from these declarations.  

Command is simple to use for simple applications but also scales well as your needs grow more complex. In particular, Command provides a sophisticated subcommand mode that groups related commands together as the complexity of your user interface grows.
A list of commonly used resources that I find helpful are listed in the acknowledgements.

<!--Built with -->
### Built With

<br>

* [opencv](https://opencv.org/)
* [cmake](https://cmake.org/)
* [gnu](https://www.gnu.org/)
* [boost](https://www.boost.org/)

<br>

## File Structure

### Folders

* [src/](src/): c++ definitions.


### Entire Files Structure 


```
.
├── CMakeLists.txt
├── include
├── README.md
└── src
    ├── boost
    │   └── boost.cpp
    ├── CMakeLists.txt
    ├── gnu
    │   └── gnu.cpp
    └── opencv
        └── opencv.cpp

5 directories, 6 files

```


<!-- GETTING STARTED -->
## Getting Started

This is a sample code of how you may configure a command line parser.
To get a local copy up and running follow these simple steps.

### Prerequisites

This is an example of how to list things you need to use the software and how to install them.
* cmake
  ```sh
  sudo apt-get install cmake
  ```
* [boost](https://stackoverflow.com/questions/8430332/uninstall-boost-and-install-another-version)
  ```sh
  cd /opt
  mkdir boost
  sudo apt-get -y install build-essential g++ python-dev autotools-dev libicu-dev libbz2-dev
  wget http://downloads.sourceforge.net/project/boost/boost/1.76.0/boost_1_76_0.tar.gz
  tar -zxvf boost_1_76_0.tar.gz
  cd boost_1_76_0
  # get the no of cpucores to make faster
  cpuCores=`cat /proc/cpuinfo | grep "cpu cores" | uniq | awk '{print $NF}'`
  echo "Available CPU cores: "$cpuCores
  ./bootstrap.sh  # this will generate ./b2
  sudo ./b2 --with=all -j $cpuCores install
  ```
 * Check boost version
  ```sh
  cat /usr/local/include/boost/version.hpp | grep "BOOST_LIB_VERSION"
  ```
 * Result
  ```sh
  // BOOST_LIB_VERSION must be defined to be the same as BOOST_VERSION
  #define BOOST_LIB_VERSION "1_76_0"
  ```
* opencv4

 *Installation*
 ```sh
 sudo su
 ```
 ```sh
git clone https://github.com/zoumson/OpencvInstall.git     \
&& cd OpencvInstall && chmod +x install.sh && ./install.sh
 ```  

### Installation

1. Install first `opencv4` cpp libraries at [https://opencv.org/](https://opencv.org/)
2. Clone the repo
   ```sh
   git clone https://github.com/zoumson/CommandLineWithOpenCVBoostGNU.git
   ```
3. Go to the project directory source
   ```sh
   cd CommandLineWithOpenCVBoostGNU
   ```
4. Create empty directories `build`, and `bin`
   ```sh
   mkdir build && mkdir bin
   ```
5. Generate the exectutables and move it to `bin`
   ```sh
   cd build && cmake .. && make && cd ..
   ``` 
<!-- USAGE EXAMPLES -->
### Usage
1. GNU
* Command line arguments 
```
#########################################################################
./bin/gnu [options]
[options]
[O]	-f [Parameter #1]		First paramter is a floating number.
[O]	-s [Parameter #2]		Second parameter has default value [5].
[O]	-t [Parameter #3]		Third parameter has enabling feature [Boolean Type].
[O]	-o [Parameter #4]		Fourth parameter has enabling feature [Boolean Type].
[M]	-i [Parameter #5]		Fith parameter is a required string.
[O]	-x [Parameter #6]		Sixth parameter has a set of options with default value[START].
[O]	-h 

```
* Run with  `gnu`
```
./bin/gnu -f 11.5 -t -i github -x end
```
* Output
```
[First] parameter is set to [11.500000]
[Second] parameter is set to [5]
[Third] parameter is set to [true]
[Fourth] parameter is set to [false]
[Fith] parameter is set to [github]
[Sixth] parameter is set to [END]

```


2. OpenCV
* Command line arguments 
```
#########################################################################
Usage: opencv [params] 

	-?, -h, --help, --usage (value:true)
		show help message
	-f, --first (value:11.5)
		First paramter is a floating number.
	--fith, -i (value:<none>)
		Fith parameter is a required string.
	--fourth, -o (value:false)
		Fourth parameter has enabling feature [Boolean Type].
	-s, --second (value:5)
		Second parameter has default value [5].
	--sixth, -x (value:1)
		Sixth parameter has a set of options with default value[1].
	-t, --third (value:false)
		Third parameter has enabling feature [Boolean Type].
```
* Run with  `opencv`
```
./bin/opencv -f 11.5 -t -i github -x 3
```
* Output
```
[First] parameter is set to [11.500000]
[Second] parameter is set to [5]
[Third] parameter is set to [true]
[Fourth] parameter is set to [false]
[Fith] parameter is set to [github]
[Sixth] parameter is set to [END]

```



3. Boost
* Command line arguments 
```
./bin/boost [options]:
  -h [ --help ]                   Show usage
  -f [ --first ] arg              First paramter is a floating number.
  -s [ --second ] arg (=5)        Second parameter has default value [5].
  -t [ --third ] [=arg(=1)] (=0)  Third parameter has enabling feature [Boolean
                                  Type].
  -o [ --fourth ] [=arg(=1)] (=0) Fourth parameter has enabling feature 
                                  [Boolean Type].
  -i [ --fith ] arg               Fith parameter is a required string.
  -x [ --sixth ] arg (=0)         Sixth parameter has a set of options with 
                                  default value[START].
```

* Run with  `boost`
```
./bin/boost -f 11.5 -t -i github -x 3
```
* Output
```
[First] parameter is set to [11.500000]
[Second] parameter is set to [5]
[Third] parameter is set to [true]
[Fourth] parameter is set to [false]
[Fith] parameter is set to [github]
[Sixth] parameter is set to [END]

```

<br>

## License plate number `NYSJ`
3. Back to the initial file structure configuration
   ```sh
   rm -r bin build lib result 
   ```
<!-- ROADMAP -->
## Roadmap

All the headers files are well docummented, read through the comments

<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open source community such an amazing place to be learn, inspire, and create. Any contributions you make are **greatly appreciated**.

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request



<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE` for more information.



<!-- CONTACT -->
## Contact

Adama Zouma - <!-- [@your_twitter](https://twitter.com/your_username) -->- stargue49@gmail.com

Project Link: [https://github.com/zoumson/CommandLineWithOpenCVBoostGNU](https://github.com/zoumson/CommandLineWithOpenCVBoostGNU.git)



<!-- ACKNOWLEDGEMENTS -->
## Acknowledgements
* [Google](https://www.google.com/)
* [Stack Overflow](https://stackoverflow.com/)
* [Github](https://github.com/)




<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->

[contributors-shield]: https://img.shields.io/github/contributors/othneildrew/Best-README-Template.svg?style=for-the-badge
[contributors-url]: https://github.com/othneildrew/Best-README-Template/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/othneildrew/Best-README-Template.svg?style=for-the-badge
[forks-url]: https://github.com/othneildrew/Best-README-Template/network/members
[stars-shield]: https://img.shields.io/github/stars/othneildrew/Best-README-Template.svg?style=for-the-badge
[stars-url]: https://github.com/othneildrew/Best-README-Template/stargazers
[issues-shield]: https://img.shields.io/github/issues/othneildrew/Best-README-Template.svg?style=for-the-badge
[issues-url]: https://github.com/othneildrew/Best-README-Template/issues
[license-shield]: https://img.shields.io/github/license/othneildrew/Best-README-Template.svg?style=for-the-badge
[license-url]: https://github.com/othneildrew/Best-README-Template/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: linkedin.com/in/adama-zouma-553bba13a
[product-screenshot]: images/screenshot.png


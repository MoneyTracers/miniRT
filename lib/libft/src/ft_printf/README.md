<!-- Improved compatibility of back to top link: See: https://github.com/othneildrew/Best-README-Template/pull/73 -->

<a  name="readme-top"></a>

<!--

*** Thanks for checking out the Best-README-Template. If you have a suggestion

*** that would make this better, please fork the repo and create a pull request

*** or simply open an issue with the tag "enhancement".

*** Don't forget to give the project a star!

*** Thanks again! Now go create something AMAZING! :D

-->

<!-- PROJECT SHIELDS -->

<!--

*** I'm using markdown "reference style" links for readability.

*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).

*** See the bottom of this document for the declaration of the reference variables

*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.

*** https://www.markdownguide.org/basic-syntax/#reference-style-links

-->

[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]


<!-- PROJECT LOGO -->

<br />
<div align="center">
  <a href="https://github.com/sebastianpenning/ft_printf">
    <img src="resources/images/logo.png" alt="Logo" width="150" height="150">
  </a>

  <h3 align="center">ft_printf</h3>

  <p align="center">
    ft_printf is a 42 version of printf
    <br />
    <a href="https://github.com/sebastianpenning/ft_printf"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/sebastianpenning/ft_printf">View Demo</a>
    ·
    <a href="https://github.com/sebastianpenning/ft_printf/issues">Report Bug</a>
    ·
    <a href="https://github.com/sebastianpenning/ft_printf/issues">Request Feature</a>
  </p>
</div>



<!-- TABLE OF CONTENTS -->

<details>
<summary>Table of Contents</summary>
<ol>
<li>
<a  href="#about-the-project">About The Project</a>
<ul>
<li><a  href="#built-with">Built With</a></li>
</ul>
</li>
<li>
<a  href="#getting-started">Getting Started</a>
<ul>
<li><a  href="#installation">Installation</a></li>
</ul>
</li>
<li><a  href="#usage">Usage</a></li>
<li><a  href="#roadmap">Roadmap</a></li>
<li><a  href="#license">License</a></li>
<li><a  href="#acknowledgments">Acknowledgments</a></li>
</ol>
</details>


<!-- ABOUT THE PROJECT -->

# About The Project

  
ft_printf is a project at Codam that teaches you about variadic variables and how they can be applied to re-engineer printf. In the project it was specifically stated not to reenact the buffer management of the original printf.


<p  align="right">(<a  href="#readme-top">back to top</a>)</p>


# Built With

* [![C][C]][C-url]

<p  align="right">(<a  href="#readme-top">back to top</a>)</p>

<!-- GETTING STARTED -->

# Getting Started

  

This is an example of how you may give instructions on setting up your project locally.

To get a local copy up and running follow these simple example steps.


# Installation
1. Clone the repo with --recursive flag, which is necessary for the tester


```sh

git clone https://github.com/sebastianpenning/ft_printf.git --recursive

```
2. cd into directory

```sh

cd ft_printf

```


3. Call the Makefile 

```sh

make

```

4. Copy libftprintf.a and ft_printf.h files over to working directory

```sh

cp {location} ft_printf.h {working directory}
cp {location} libftprintf.a {working directory}

```

<a href="https://github.com/sebastianpenning/ft_printf">
  <img src="resources/images/cpy_files.png" alt="cpy_files" width="1100" height="130">
</a>

<!-- USAGE EXAMPLES -->

# Usage

1. Include libft.h file and libft function in project.

<a href="https://github.com/sebastianpenning/ft_printf">
  <img src="resources/images/include_files.png" alt="include_files" width="800" height="175">
</a>


2. Compile with cc

```sh
cc -Wall -Werror -Wextra {project_files.c} libftprintf.a && ./a.out
```

<a href="https://github.com/sebastianpenning/ft_printf">
  <img src="resources/images/compile_printf.png" alt="compile_printf" width="1100" height="100">
</a>



# Tester


The libft tester includes tests for libft, printf, and get_next_line with both unit tests and norminette
tests for all files included. In the future memory tests are planned to be added.

1. cd into ft_printf_testser

<a href="https://github.com/sebastianpenning/libft">
  <img src="resources/images/tester_1.png" alt="tester_1" width="900" height="150">
</a>

2. Make tests

<a href="https://github.com/sebastianpenning/libft">
  <img src="resources/images/tester_2.png" alt="tester_2" width="900" height="700">
</a>


# Roadmap

- [ ]

See the [open issues](https://github.com/sebastianpenning/ft_printf/issues) for a full list of proposed features (and known issues).

<p  align="right">(<a  href="#readme-top">back to top</a>)</p>

<!-- LICENSE -->

# License

Distributed under the MIT License. See `LICENSE.txt` for more information.

 
<p  align="right">(<a  href="#readme-top">back to top</a>)</p>

<!-- ACKNOWLEDGMENTS -->

# Acknowledgments

* [Codam](https://www.codam.nl/about-codam) 
* [Readme Template](https://github.com/othneildrew/Best-README-Template/tree/master)

<p  align="right">(<a  href="#readme-top">back to top</a>)</p>


<!-- MARKDOWN LINKS & resources/IMAGES -->

<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->

[contributors-shield]: https://img.shields.io/github/contributors/sebastianpenning/ft_printf.svg?style=for-the-badge

[contributors-url]: https://github.com/sebastianpenning/ft_printf/graphs/contributors

[forks-shield]: https://img.shields.io/github/forks/sebastianpenning/ft_printf.svg?style=for-the-badge

[forks-url]: https://github.com/sebastianpenning/ft_printf/network/members

[stars-shield]: https://img.shields.io/github/stars/sebastianpenning/ft_printf.svg?style=for-the-badge

[stars-url]: https://github.com/sebastianpenning/ft_printf/stargazers

[issues-shield]: https://img.shields.io/github/issues/sebastianpenning/ft_printf.svg?style=for-the-badge

[issues-url]: https://github.com/sebastianpenning/ft_printf/issues

[license-shield]: https://img.shields.io/github/license/sebastianpenning/ft_printf.svg?style=for-the-badge

[license-url]: https://github.com/sebastianpenning/ft_printf/blob/main/LICENSE

[C]:https://img.shields.io/badge/-c-black?logo=c&style=social

[C-url]: https://www.learn-c.org/
  


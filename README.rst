Mandelbrot Explorer
###################
:Author: Roie R. Black
:Date: Nov 18,2018
:Course: COSC1337 - Programming Fundamentals II
:Docs: https://rblack42.github.io/mandelbrot

|travis-build| |license|

This repo contains sample code used by students in my class. The project is not
well structured, and has issues that students will work to fix. As delivered it
does run, but has issues needing attention.

To run this project do the following:

    1. Make sure Standard C++/make tools are installed. You also need
           ``python3`` and ``pip`` on the host machine

    2. Run ``git clone https://github.com/rblack42/Mandelbrot.git``

    3. Run ``cd mandelbrot``

    4. Run ``make reqs`` to instal python dependencies.

    5. Run ``make help`` to see available commands

Documentation is written using reStructuredText, and is processed using Python Sphinx. Turn on the website setting on your GitHub repository and run "make html". When you push your code the output will be available at your account URL.

..  warning::

    The ``Vagrantfile`` file and the ``ansible`` directory are used for testing
    this project non a Linux virtual machine. Students normally do not use any
    of that capability.

..  |travis-build| image:: https://travis-ci.org/rblack42/Mandelbrot.svg?branch=master
    :alt: Build badge from Travis-CI

..  |license| image:: https://img.shields.io/badge/License-BSD%203--Clause-blue.svg
    :alt: BSD 3-Clause License


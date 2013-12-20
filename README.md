STM32F0-Template
================

Simple template for creating projects of the STM32F0 (e.g. the discovery board)

Contains a template for projects using the stm32f0 discovery board, 
gnu toolchain (see https://launchpad.net/gcc-arm-embedded)
and the STM32F0xx Standard Peripheral Library.

To test:

   (1) install the toolchain and libarary.
   (2) change the TOOLROOT and LIBROOT paths in Makefile.common
   (3) cd to Demo
   (4) type make

To create new projects

   (1) clone the Demo directory (name the directory appropriately)
   (2) change TEMPLATEROOT in the cloned makefile to point to the template directory
   (3) modify as needed, adding any needed library objects to the OBJ list in the Makefile

To execute:

I recommend the st-util program as a gdb server 

https://github.com/texane/stlink

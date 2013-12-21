STM32F0-Template
================

Simple template for creating projects of the STM32F0 (e.g. the discovery board)

Contains a template for projects using the stm32f0 discovery board, 
gnu toolchain (see https://launchpad.net/gcc-arm-embedded)
and the STM32F0xx Standard Peripheral Library.

To test:

   (1) install the toolchain and libarary.

   (2) change the TOOLROOT and LIBROOT paths in Makefile.common  
   
       you may need to change
       
       DEVICE=$(LIBROOT)/CMSIS/Device/ST/STM32F0xx
       
       to
       
       DEVICE=$(LIBROOT)/CMSIS/ST/STM32F0xx
       
       if you are using the (older) version of the peripheral library distributed with the original F0 discovery board.  
       ST has changed the file layout slightly)

   (3) cd to Demo

   (4) type make

To create new projects

   (1) clone the Demo directory (name the directory appropriately)

   (2) change TEMPLATEROOT in the cloned makefile to point to the template directory

   (3) modify as needed, adding any needed library objects to the OBJ list in the Makefile

To execute:

I recommend the st-util program as a gdb server 

https://github.com/texane/stlink

==================

The standard peripheral library can be difficult to crack.  Here are two hints to
get you started.

    (1) Use doxygen to generate documentation
       -- cd to the directory containing the standard peripheral library

       -- generate a config file (you can edit this, but don't need to)
       	   doxygen -g config_file
       -- generate the documentation.  This will genererate html 
          and latex directories (you can  modify the config file to 
          turn off either of these).  
          
	  doxygen config_file

       -- Open html/index.html to see the  documentation

       (2) I wrote a lab manual for a similar processor (the stm32f100), 
           but beware, there are many small differences in the standard 
           peripheral library. Nevertheless, the big picture is the same.

   http://www.cs.indiana.edu/~geobrown/book.pdf



# ft_printf
<img width="1910" alt="Graded by Deepthought" src="https://user-images.githubusercontent.com/74931024/111147201-80ee1600-858a-11eb-91bf-08ce19846b36.png">

The definition of this project is simple: replicate the workings of the famous **printf** function. Thanks to this, it won't be necessary for us to continue using
**ft_putchar_fd** and **ft_putstr_fd** every time we want to display a character, a string of characters or a number on the screen.

### MAIN OBJECTIVES
The main objective that we want to achieve with this project is to be able to define functions that receive a **variable number of arguments**.
Up to now, every time we define the prototype of a function, we establish a series of mandatory (fixed) parameters that must be entered when calling
the function. However, we can see that a function like printf can receive as many parameters as the user specifies.
So how is it able to do this? The simple answer is found in the use of the **<stdarg.h>** library.

### <stdarg.h>
This library will allow us to work with the use of functions capable of receiving a variable number of arguments.
To do this, you will declare a new type of variable and three different macros:
<ul>
  <li><b>va_list</b>  -->  variable</li>
  <li><b>va_start</b>  -->  macro</li>
  <li><b>va_arg</b>  -->  macro</li>
  <li><b>va_end</b>  -->  macro</li>
</ul>

If you want to know more about how to use each of these macros, you already know the answer: **RTFM**. However, if you want to ask me a question or
discuss about some functionality of this library, you can do it through the <a href="https://github.com/pgomez-a"> contact information of my README:
I'll be happy to talk to you !! </a>

### RETURN VALUES
Although the use of printf consists of displaying a format string on the standard output **(stdin;)**, it also has a return value, since it is
a function of type int. This return will be the number of characters you have printed on the screen, and not the number of characters in the format string.

### EXAMPLES OF USE
Some examples of the use of our **ft_printf**, comparing it with the real **printf** and being **ft = output_printf** and **sy = output_ft_printf**:<br>
<img width="200" align="left" alt="Regular case main" src="https://user-images.githubusercontent.com/74931024/111148223-aa5b7180-858b-11eb-89e5-a6be28b392f3.png">
<img width="208" align="center" alt="Regular example main" src="https://user-images.githubusercontent.com/74931024/111148813-6157ed00-858c-11eb-8042-18a3dbfe252f.png">
<br><br>
<img width="200" alt="Regular case main" src="https://user-images.githubusercontent.com/74931024/111150357-4c7c5900-858e-11eb-939b-4a6aec33f1d7.png">
<img width="220" alt="Regular example main" src="https://user-images.githubusercontent.com/74931024/111150535-80f01500-858e-11eb-81dc-e8c33982fd9e.png">
<br><br>
However, there are some particular cases that we must take into account, both when working with the computer memory and when making a correct cast: <br>
<img width="1733" alt="Special case main.c" src="https://user-images.githubusercontent.com/74931024/111147729-14bfe200-858b-11eb-84c9-8bd045af08cc.png">
<img width="2225" alt="Special case example" src="https://user-images.githubusercontent.com/74931024/111147835-3325dd80-858b-11eb-82a4-a2ad7a18cf05.png">

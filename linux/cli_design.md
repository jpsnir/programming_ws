# command line design guidelines

-[POSIX utilities
guidelines](https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap12.html)
- [GNU coding
    conventions](https://www.gnu.org/prep/standards/standards.html#Command_002dLine-Interfaces)
- [stackexchange  - good habits for designing
    cli](https://softwareengineering.stackexchange.com/questions/307467/what-are-good-habits-for-designing-command-line-arguments)
- mimic the behavior of popular programs - cmake, git 
    - `-n` -> dry run
    - `-v` -> verbosity
    -
- often use `-` for standard input or output
- In some cases, embed an interpreter like GNU guile or Lua in
  your software. 

- library similar to argparse - [tclap](https://github.com/mirror/tclap.git)
- [getopt
    library](https://www.gnu.org/software/libc/manual/html_node/Using-Getopt.html)

## source : chatgpt
# Interactive bash scripts
Interactive bash scripts are shell scripts that interact with the user, prompting for input and responding to user choices or actions. They allow for a more dynamic and personalized user experience compared to regular non-interactive scripts that run without user intervention. Here are some key points and examples on how to create interactive bash scripts:

**1. User Input:**
To get user input in a bash script, you can use the `read` command. The `read` command reads a line of input from the user and stores it in a variable. Here's a simple example:

```bash
#!/bin/bash

echo "What's your name?"
read name
echo "Hello, $name!"
```

**2. Prompting for Confirmation:**
You can prompt the user for a yes/no confirmation using the `read` command and a loop. Here's an example:

```bash
#!/bin/bash

echo "Do you want to continue? (y/n)"
read choice

# Convert the choice to lowercase for case-insensitivity
choice=${choice,,}

if [[ $choice == "y" ]]; then
    echo "You chose to continue."
else
    echo "You chose to cancel."
fi
```

**3. Menus and Selections:**
You can create simple menus for the user to select options using a combination of `echo`, `read`, and a `case` statement. Here's an example:

```bash
#!/bin/bash

echo "Select an option:"
echo "1. Option 1"
echo "2. Option 2"
echo "3. Option 3"
read choice

case $choice in
    1)
        echo "You selected Option 1."
        ;;
    2)
        echo "You selected Option 2."
        ;;
    3)
        echo "You selected Option 3."
        ;;
    *)
        echo "Invalid choice."
        ;;
esac
```

**4. Loops for Repeated Interaction:**
You can use loops to repeat interactions until a specific condition is met. Here's an example that keeps asking for a number until a valid positive integer is provided:

```bash
#!/bin/bash

while true; do
    echo "Enter a positive integer:"
    read num

    if [[ $num =~ ^[1-9][0-9]*$ ]]; then
        echo "Valid positive integer: $num"
        break
    else
        echo "Invalid input. Please try again."
    fi
done
```

**5. Using Functions:**
To organize your interactive bash script, you can define functions for different actions and use them throughout the script. This can make the code more modular and easier to maintain.

```bash
#!/bin/bash

function greet_user() {
    echo "What's your name?"
    read name
    echo "Hello, $name!"
}

function confirm_action() {
    echo "Do you want to proceed? (y/n)"
    read choice

    choice=${choice,,}

    if [[ $choice == "y" ]]; then
        echo "Action confirmed."
    else
        echo "Action canceled."
    fi
}

greet_user
confirm_action
```

Remember that interactive scripts should provide clear and informative messages to guide the user. Properly handle unexpected inputs and errors to provide a smooth and user-friendly experience. Always consider edge cases and implement validation for user inputs when necessary.

# Expect
Using the `expect` utility, you can create more complex interactive scripts, particularly when interacting with other command-line programs that require interactive input. `expect` allows you to automate interactions by providing pre-determined responses to prompts and can be used for various purposes, including automating SSH logins, executing CLI commands with input, and more.

To achieve similar functionality as the previous examples using `expect`, you'll need to install `expect` on your system, as it is not a built-in bash command. You can typically install it using your package manager (e.g., `apt-get` or `yum` on Linux, or Homebrew on macOS).

Here's how you can use `expect` to create interactive scripts:

**1. Installing Expect:**
Make sure `expect` is installed on your system. For example, on Ubuntu or Debian-based systems, you can install it using:

```bash
sudo apt-get install expect
```

**2. Interactive Bash Script with Expect:**

Let's create an interactive script using `expect` to perform similar tasks as the examples above.

```bash
#!/usr/bin/expect -f

# Prompting for user input
send_user "What's your name? "
expect_user -re "(.*)\n"
set name $expect_out(1,string)
send_user "Hello, $name!\n"

# Prompting for confirmation
send_user "Do you want to continue? (y/n) "
expect_user -re "(.*)\n"
set choice [string tolower $expect_out(1,string)]

if {$choice eq "y"} {
    send_user "You chose to continue.\n"
} else {
    send_user "You chose to cancel.\n"
}

# Creating a menu and handling selections
send_user "Select an option:\n"
send_user "1. Option 1\n"
send_user "2. Option 2\n"
send_user "3. Option 3\n"
expect_user -re "(.*)\n"
set choice $expect_out(1,string)

switch -- $choice {
    1 {
        send_user "You selected Option 1.\n"
    }
    2 {
        send_user "You selected Option 2.\n"
    }
    3 {
        send_user "You selected Option 3.\n"
    }
    default {
        send_user "Invalid choice.\n"
    }
}

# Using a loop for repeated interaction
while {1} {
    send_user "Enter a positive integer: "
    expect_user -re "(.*)\n"
    set num $expect_out(1,string)

    if {[string is integer $num] && $num > 0} {
        send_user "Valid positive integer: $num\n"
        break
    } else {
        send_user "Invalid input. Please try again.\n"
    }
}
```

**3. Running the Expect Script:**
Save the above script in a file (e.g., `interactive_script.expect`) and give it execute permission:

```bash
chmod +x interactive_script.expect
```

Now you can run the `expect` script as follows:

```bash
./interactive_script.expect
```

The script will interact with the user as described and provide responses based on the user's input, just like the interactive bash script examples. `expect` enables you to automate user interactions, making it powerful for automating CLI tasks and creating more complex interactive scripts.

# expect in bash
Using the `expect` utility, you can create more complex interactive scripts, particularly when interacting with other command-line programs that require interactive input. `expect` allows you to automate interactions by providing pre-determined responses to prompts and can be used for various purposes, including automating SSH logins, executing CLI commands with input, and more.

To achieve similar functionality as the previous examples using `expect`, you'll need to install `expect` on your system, as it is not a built-in bash command. You can typically install it using your package manager (e.g., `apt-get` or `yum` on Linux, or Homebrew on macOS).

Here's how you can use `expect` to create interactive scripts:

**1. Installing Expect:**
Make sure `expect` is installed on your system. For example, on Ubuntu or Debian-based systems, you can install it using:

```bash
sudo apt-get install expect
```

**2. Interactive Bash Script with Expect:**

Let's create an interactive script using `expect` to perform similar tasks as the examples above.

```bash
#!/usr/bin/expect -f

# Prompting for user input
send_user "What's your name? "
expect_user -re "(.*)\n"
set name $expect_out(1,string)
send_user "Hello, $name!\n"

# Prompting for confirmation
send_user "Do you want to continue? (y/n) "
expect_user -re "(.*)\n"
set choice [string tolower $expect_out(1,string)]

if {$choice eq "y"} {
    send_user "You chose to continue.\n"
} else {
    send_user "You chose to cancel.\n"
}

# Creating a menu and handling selections
send_user "Select an option:\n"
send_user "1. Option 1\n"
send_user "2. Option 2\n"
send_user "3. Option 3\n"
expect_user -re "(.*)\n"
set choice $expect_out(1,string)

switch -- $choice {
    1 {
        send_user "You selected Option 1.\n"
    }
    2 {
        send_user "You selected Option 2.\n"
    }
    3 {
        send_user "You selected Option 3.\n"
    }
    default {
        send_user "Invalid choice.\n"
    }
}

# Using a loop for repeated interaction
while {1} {
    send_user "Enter a positive integer: "
    expect_user -re "(.*)\n"
    set num $expect_out(1,string)

    if {[string is integer $num] && $num > 0} {
        send_user "Valid positive integer: $num\n"
        break
    } else {
        send_user "Invalid input. Please try again.\n"
    }
}
```

**3. Running the Expect Script:**
Save the above script in a file (e.g., `interactive_script.expect`) and give it execute permission:

```bash
chmod +x interactive_script.expect
```

Now you can run the `expect` script as follows:

```bash
./interactive_script.expect
```

The script will interact with the user as described and provide responses based on the user's input, just like the interactive bash script examples. `expect` enables you to automate user interactions, making it powerful for automating CLI tasks and creating more complex interactive scripts.

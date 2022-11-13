# Greeble

Greeble is a birds-eye view OOP project manager and generator.

It uses a simple high-level syntax to automatically generate project files.
This allows the developer to construct the overall architecture of the program, such as the design patterns involved, before jumping into implementation.

## Getting started
Once Greeble is installed in your system, simply create a directory where your project will be installed, containing a `.greeble` configuration file.

Once you've set up your `.greeble` file with all classes and patterns, run the `greeble` command from within that directory.

```sh
mkdir yourProject
cd yourProject
touch .greeble
greeble
```
# Nate's Unix Tools

Some little C programmes I wrote.
Each is meant to solve one particular problem and nothing else.

Every `.c` file under `tools` is a standalone tool.
To add your own tools just add your C-File to the `tools` directory and it will be compiled.

# Tools

* gcol - Print nth column of stdin
* columnify - Make table out of stdin with a given separator
* number - Number lines of stdin
* frequency - List words in order of their frequency
* rtree - Find files recursive

# Build

To build every tool just type:

```
make
```

And if you want to install it use:

```
sudo make install
```

# Participate 

## Some Rules

In order to keep every programme small there are some rules I made especially for myself to stay on track.

1. Do not make the tools to big and almost *featureless*. It is better to split some tools into to parts.

2. Write the programme in C. This tool is *not* a big application so you will not need some object-oriented programming or some other fancy stuff. That helps to keep the tools small and effective.

3. Do not use any additional library. The Standard-Library is enough to solve little problems.

4. Have fun.


If you need some help or if you have questions, just ask.
I love to see incredible ideas.
If you are stuck just ask for help or inspiration.

# Software Systems Project Proposal
Team Cynthesis: Ilya Besancon, Duncan Hall

*Start Date: Week of Feb 19th*

*End Date: Report due March 26th*

## 1) Project Scope

As a lower bound, we will begin by creating a static vst plugin with no GUI, just a unit that gives you one flavor of saw/sine/square wave output. From there we can begin experimenting with providing access to parameters through a basic GUI (very basic. GUIs are not where we want to focus this project). With a couple settable parameters, we will move to very basic synthesis and midi control. 

Stretch goals for the project will be either to continue down the synthesis route by implementing standard frequency modulation processes, or instead going down the sampler route whereby sounds can be imported to the plugin, stored in a local library, and played back at varying pitch.

## 2) Learning Goals

We would like to use this first project as an opportunity to use C/C++ in real application setting and gain understanding around structuring and implementation both using C and in the domain of vst (virtual studio technology) plugin creation. It will also be an opportunity to learn more about how to emulate effects and synthesizers in software, and keep our eye out for processes that can only be implemented in software rather than traditional analog methods. This project will also provide an opportunity to get pretty deep into thread management as limiting latency is key when creating software instruments and running audio effects through a DAW.

## 3) Resources Needed

We have had no trouble finding resources to get us started in this project. We have found a tutorial by Martin Finke on making audio plugins which looks very comprehensive and user-friendly. From initial searching, programming plugins seems like a fairly well documented process in various other places on the internet as well (see links at the bottom of this document).

## 4) First Steps

Find 3 additional sources of code/tutorials on audio plugins

- Done = added to list of resources

Get our environments set up with requisite resources.

- Done = Ready to write and compile C++ code into vst

Write a basic oscillator

- Done = we have an instrument to play in the DAW (not yet customizable at all though)!


## Resource Library:

- http://www.martin-finke.de/blog/articles/audio-plugins-001-introduction/
- https://ethanwiner.com/eq-dsp.htm

### Digital Sound Processing Open Source Code:

- http://musicdsp.org/
- http://musicdsp.org/archive.php?classid=1#269
- https://rhordijk.home.xs4all.nl/G2Pages/index.htm



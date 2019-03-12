# Software Systems Project Update
Team Cynthesis: Ilya Besancon, Duncan Hall

*Start Date: Week of Feb 19th*

*End Date: Report due March 26th*

## 1) Project Scope

As a lower bound, we chose to create a static vst plugin with no GUI, just a unit that gives you one flavor of saw/sine/square wave output. From there we’ve experimented with providing access to parameters through a basic GUI (very basic. GUIs are not where we want to focus this project). We developed a simple volume slider plugin with GUI, and are presently moving on to very basic synthesis. (Midi control has turned out to be very simple, and is already implemented.)

Stretch goals for the project will be either to continue down the synthesis route by implementing standard frequency modulation processes, or instead going down the sampler route whereby sounds can be imported to the plugin, stored in a local library, and played back at varying pitch. Definitely a much larger jump to this level of complexity, so we’ll see how far we can get in this next sprint.

## 2) Learning Goals

We would like to use this first project as an opportunity to use C/C++ in real application setting and gain understanding around structuring and implementation both using C and in the domain of vst (virtual studio technology) plugin creation. It will also be an opportunity to learn more about how to emulate effects and synthesizers in software, and keep our eye out for processes that can only be implemented in software rather than traditional analog methods. This project will also provide an opportunity to get pretty deep into thread management as limiting latency is key when creating software instruments and running audio effects through a DAW.

## 3) Resources Needed

We have had no trouble finding resources to get us started in this project. We have found a tutorial by Martin Finke on making audio plugins which looks very comprehensive and user-friendly. From initial searching, programming plugins seems like a fairly well documented process in various other places on the internet as well (see links at the bottom of this document).

We have also found the Juce (a framework for developing VST plugins) tutorials helpful, though there is more to learn in between such tutorials (many tutorials have project file downloads to start with where steps are skipped and things are already implemented for you).


## 4) Next Steps

- Get access to plugin audio output
	- Done = plugin plays a sine wave, static noise, or pipes audio in to out (not exactly what a fm synthesizer does, but we’re also interested in sampling potentially)
- Create a synthesizer using a couple different oscillators 
	- Done = outputs sound and has a single modulation knob
- Integrate synthesizer with midi input
	- Done = can take input from midi and output sound
- Test running plugin in FL Studio 12 (or another DAW)
	- Done = it imports, scans, and runs!!
- Update Trello Board with these tasks
	- Done = tasks have been added

## Resource Library:

- http://www.martin-finke.de/blog/articles/audio-plugins-001-introduction/
- https://ethanwiner.com/eq-dsp.htm
- https://juce.com/learn/tutorials

### Digital Sound Processing Open Source Code:

- http://musicdsp.org/
- http://musicdsp.org/archive.php?classid=1#269
- https://rhordijk.home.xs4all.nl/G2Pages/index.htm

### SDK from Steinberg:
- https://www.steinberg.net/en/company/developers.html


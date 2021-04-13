### Solver gravity

I had some problem with the new library "CURSES" that I didn't use before. I prepared for the interview and watch some videos about how to use this library, also I had a problem with it and spent a lot of time for it.
<br>
The task was really interesting, I have never write a console game like this.

#### Algorithm

<p align="center">
  <img src="https://i.ibb.co/tsN6DwJ/image.png" width="350" title="hover text">
</p>

In order not to go through the matrix of signs each time and not to search for 4 identical signs sequentially, we store in memory an "array of signs" of the same dimension, where for each element we store an array of two numbers, the number of identical signs vertically and horizontally, respectively. Thus, when adding a new sign to a field, we check the neighboring fields in the "feature matrix", while we do not check the upper field, since we have a Solver with"Gravity".

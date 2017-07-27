# RandomMapGenerator
Creates randomly generated 2D tile maps using the SFML library

![Screenshot][https://gyazo.com/1dd62e937f89b0df29fc48ff9766d738]



Uses an algorithm that adds columns and rows to a 1 dimensional vector that is represented in 2 dimensions. 
Then uses a version of nearest neighbor interpolation to determine the value at the points in the newly created rows and columns.

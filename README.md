/* Learning-to-code
Student projects for cs50 and assorted experimentation

int main(void)
{
     CS50 Week 0;
     ------------
          First project is to make a game in Scratch;
          I'm making a little basketball shooting game :)
     
          I also uploaded my week 0 #cs50 game to the Scratch website, so you can now revel in the awkward graphics, 
          janky lunar-gravity physics, and "sweet" tunes from the comfort of your desktop/laptop browser.

          Aiming digital basketballs at a net is not gonna change your life, 
          but I had a blast hacking together solutions to the coding puzzles I created for myself. 

          (My high score is 19, btw)
     
          https://scratch.mit.edu/projects/774428366/
     
     
     
     Cs50 Week 1 (second week, translating the Scratch concepts to C);
     -----------------------------------------------------------------
          Malan is a fantastic teacher, introducing concepts, syntax, and terminology at a pace that rewards concentration, 
          but rarely feels rushed. Wish I'd done this years ago!

          Watched the first half, banged out a 'Mario-more' solution, then watched the second half, defined some functions, 
          and rewrote it. Still a bit fuzzy on the syntax for defining/calling functions. Practice, I guess.

          Tonight: the cash/credit problems. Fun!
     
          ...
     
          Whew ok

          Cash was pretty straightforward (most of the code was given).

          Credit taught me some Fun Lessons

          - int vs long and how the computer is likely handling them within functions
          - you can't define a function inside another function
          - grasping how to define vs call vs point to functions is a bit head-spinning at first
          - using printf to debug is really handy
          - don't assume you did your math right, unless you want to stare at the screen forever, good times ;)
          
          
     Cs50 week 2, scrabble & readability;
     ------------------------------------
          Okay, function calls make sense now

          Had a mental block wrt how a function's inputs/returns are named in main
          (where they're named based on the specific intention for that function call) vs how they appear in the actual function 
          definition (where the names are more about the function's generalized operation). 

          *Now* it all seems obvious...

          Anyway, also forgot the single quotes + backslash of '\0' in scrabble.c for a while, good times!
     
     
     (Readability.c)
     ---------------
          Banged out most of it fairly quickly until the last f(x) where the letter, word, and sentence counts go into an equation:
     
          1: Neglected to initialize an int that only appeared in the 'else' brackets of an if-else, 
          but still tried to return that int value, oops;

          2: Learned something about when type-casting is necessary in order to get a float output, 
          i.e. if x and y are ints, then 
          {
               float z = (x/y) * 100.0 
          }
          doesn't work.

     
          Live && learn!


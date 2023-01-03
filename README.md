/* Learning-to-code
Student projects for cs50 and assorted experimentation

const string academic_honesty = "Harvard says that sharing solutions to the problems,
or making them available, violates their academic honesty policy. So while I'd
like to share my work, I did choose to take advantage of the course being offered
for free (as in beer). So this will just be a record of some of the challenges faced,
mistakes made, and successes achieved along the way.\n";

int main(void)
{
     CS50_week_0(scratch)
     {
          First project is to make a game in Scratch;
          I'm making a little basketball shooting game :)
     
          I also uploaded my week 0 #cs50 game to the Scratch website, so you can now revel in the awkward graphics, 
          janky lunar-gravity physics, and "sweet" tunes from the comfort of your desktop/laptop browser.

          Aiming digital basketballs at a net is not gonna change your life, 
          but I had a blast hacking together solutions to the coding puzzles I created for myself. 

          (My high score is 19, btw)
     
          https://scratch.mit.edu/projects/774428366/
     }
     
     
     Cs50_week_1(second week, translating the Scratch concepts to C)
     {
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
     }     
          
     Cs50_week_2(scrabble & readability, in c)
     {
          Part_1(Scrabble.c)
          {
               Okay, function calls make sense now

               Had a mental block wrt how a function's inputs/returns are named in main
               (where they're named based on the specific intention for that function call) vs how they appear in the actual function 
               definition (where the names are more about the function's generalized operation). 

               *Now* it all seems obvious...

               Anyway, also forgot the single quotes + backslash of '\0' in scrabble.c for a while, good times!
          }
     
          Part_2(Readability.c)
          {
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
          }
          
     Cs50_week_3(Caesar & substitution, in c)
     {
          Did both options because why not.

          Enjoying using functions now, and even though it's super early days on this journey, trying to keep an eye toward 
          writing efficient, reusable, versatile code.

          For Caesar (easier problem) 
          {
               I was a bit disappointed in the way they want you to do it; rather than building an encoded string in memory,
               it's just printf-ed a letter at a time instead.

               Butted up against data type errors for quite a while to try to do the former. Eventually relented - 
               sometimes it's actually true that you need to learn to walk before you can run!
          }
          
          For Substitution (harder problem)
          {
               this was a fun puzzle for a beginner like me - nested loops w/ functions, & the need to understand the
               naming/syntax/etc for arrays vs strings vs chars.

               Got tripped up on a loop -

               int counter = 0;
               for (int i = 0; i != '\0'; counter++)
               {}

               where I confused the 'first element is zero' rule for 'first counter++ is zero'. Rookie mistake!
               
               And also had a good self-teaching moment where I realized where the logic (of my method to check the
               validity of a user input) wasn't actually covering all the possible wrong inputs.

               In this particular case I can't imagine how it would be a security vulnerability per se. But it made it
               clear just how easy it is to unintentionally create an exploitable bug that could go completely unnoticed
               by users for quite some time.
          }
          
     Cs50_Week_3(Algorithms)
     {
          lecture_notes(recursion)
          {
               Geez, trying to understand recursive functions is like trying to understand recursive functions,
               you know what I mean?
          
               ...
          
               Ohhhhh lol ok I had a mental block around why the "return;" didn't back the 'draw' function out of itself 
               completely. Suddenly occurred to me that it's only returning out of that (n = 0) function call, thus
               allowing the rest to complete, since they're already at the line *after* draw(n - 1)

               For whatever reason, I wasn't picturing the calls as existing inside one another. I guess this is why 
               Malan recommends using the debugger to step into the code in order to see what it's doing.
          }
          
          
*/

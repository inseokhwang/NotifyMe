# NotifyMe

Ever procrastinate on a project with a long compilation/run time? Like your AI assignment that's due in few hours, and it takes like 20 minutes for each test iteration? What do you do if you have to go take a break, but you also want to make sure you have most time available to prepare for your immenent doom? What if you had to compile the kernel for the first time on your ultrabook, and god knows when your terminal would be free?

Fear no more, NotifyMe is here!
-------------------------------

NotifyMe is a program that allows users to specify a specific shell command to run and notify the user when the control of the terminal is freed to the user through free SNS system provided by [TextBelt](http://textbelt.com/), coded by Ian Webster.

How do I install it?
-------------------------------

	make

How do I use it?
-------------------------------

    ./NotifyMe <terminal code>

It's telling me that I haven't set my phone number yet? WHAT DO?

	./NotifyMe -d <phone number>

It broke my computer! What do I do?
------------------------------------

NotifyMe simply calls the terminal commands that you have specified through system(). The way your terminal command is executed might differ depending on the kernel/distribution, but my code has nothing to do with it.
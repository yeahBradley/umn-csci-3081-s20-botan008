### Assessment for Lab 10

#### Total score: _100.0_ / _100_

Run on March 03, 15:29:44 PM.


### Necessary Files and Structure

+  _10_ / _10_ : Pass: Check that directory "labs" exists.

+  _10_ / _10_ : Pass: Check that directory "labs/lab10_advanced_git" exists.


### Git Usage

+  _10_ / _10_ : Pass: Run git ls-remote to check for existence of specific branch- Branch devel found

+ Pass: Checkout devel branch.



+ Pass: Run git ls-remote gather all branches in repo

		f247f3fafbe17f052ef13066856aa39955f1465c	refs/heads/devel

		983ed32516a2efcee1c5f0f744328f5fa03b5d8e	refs/heads/fix/01-compilation-errors

		b9fb78e181fbaf4f41873d9c13736cb67dea1a5a	refs/heads/fix/02-google-style-pass

		6acbde4aea6c13635ff1ac816dfb6df48f309a5d	refs/heads/master



+  _10_ / _10_ : Pass: Checking for the correct number of branches

Sufficient branches found (found=2, required=2):

fix/01-compilation-errors

fix/02-google-style-pass


#### Counting commits on devel

+ Pass: Checkout devel branch.



+ Pass: Gather commit history

		[Bradley Botanel] 2020-02-28 (HEAD -> devel, origin/devel) Merge branch 'fix/02-google-style-pass' into devel Final cpplint error has been corrected.


		[Bradley Botanel] 2020-02-28 (origin/fix/02-google-style-pass, fix/02-google-style-pass) fix/02-google-style #2 Corrected the final cpplint error.


		[Bradley Botanel] 2020-02-27 Merge branch 'fix/02-google-style-pass' into devel Completed google style pass of .cc and .h files.


		[Bradley Botanel] 2020-02-27 fix(.cc and .h): fix #2 google-style-pass Changed .cc and .h files to be google style compliant.


		[Bradley Botanel] 2020-02-27 Merge branch 'fix/02-google-style-pass' into devel .cc and .h files are now google code compliant via cpplint


		[Bradley Botanel] 2020-02-27 style(.cc and .h files): cpplint compliance Changed the code style to be cpplint compliant.


		[Bradley Botanel] 2020-02-27 Merge branch 'fix/01-compilation-errors' into devel The compilation errors have been corrected.


		[Bradley Botanel] 2020-02-27 (origin/fix/01-compilation-errors, fix/01-compilation-errors) Testing the gitmessage 

		[Bradley Botanel] 2020-02-27 fix(files): fix #1 fix compilation errors - Several files had necessary methods commented out. They were:
- random_passenger_generator.cc; GeneratePassengers()
- bus.cc; LoadPassenger()
- passenger.cc; Update()
- stop.cc; LoadPassengers()

This has been corrected. The program compiles.


		[Bradley Botanel] 2020-02-27 #7 

		[Bradley Botanel] 2020-02-27 lab10: #4 



		[Bradley Botanel] 2020-02-27 Lab09 Final deliverables 

		[Bradley Botanel] 2020-02-26 Merge branch 'support-code' 

		[Bradley Botanel] 2020-02-26 Merge branch 'support-code' of github.umn.edu:umn-csci-3081-s20/csci3081-shared-upstream into support-code 


























































		[Bradley Botanel] 2020-02-22 Merge branch 'master' of github.umn.edu:umn-csci-3081-s20/repo-botan008 

		[Bradley Botanel] 2020-02-22 Lab08 Final Deliverables w/ cpplint pass on all files 
















		[Bradley Botanel] 2020-02-21 Lab08 Final Deliverables 


		[Bradley Botanel] 2020-02-21 lab08 Final Deliverable 


		[Bradley Botanel] 2020-02-21 Merge branch 'master' of github.umn.edu:umn-csci-3081-s20/repo-botan008 

		[Bradley Botanel] 2020-02-21 lab08 In progress 


		[Bradley Botanel] 2020-02-21 Merge branch 'support-code' 

		[Bradley Botanel] 2020-02-21 Merge branch 'support-code' of github.umn.edu:umn-csci-3081-s20/csci3081-shared-upstream into support-code 

























+  _5_ / _5_ : Pass: Check git commit history
Sufficient commits (found=36,required=4)


### Git Issue Usage

+ Pass: Configuring GHI

+ Pass: Run ghi for total number of open issues in Github repo (Found: 0)

+ Pass: Run ghi for total number of closed issues in Github repo (Found: 2)

[CLOSED issue #2] :  Google style pass [enhancement]

[CLOSED issue #1] :  Compilation Error [bug]





+  _10.0_ / _10_ : Pass: Run ghi for total number of issues in Github repo (Found: 2, Expected: 2) 

 [OPEN issue #] : 

[CLOSED issue #2] :  Google style pass [enhancement]

[CLOSED issue #1] :  Compilation Error [bug]

 




### Test that code on  devel compiles

+ Pass: Checkout devel branch.



+  _10_ / _10_ : Pass: Check that directory "project/src" exists.

+ Pass: Change into directory "project/src".

+  _5_ / _5_ : Pass: Check that file "makefile" exists.

+  _30_ / _30_ : Pass: Check that make compiles.



#### Total score: _100.0_ / _100_


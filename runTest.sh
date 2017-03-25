#! /bin/bash

TEST_FOLDER="$PWD/tests"
tests=(TestDialogs/TestImprove TestDialogs/TestLearn TestDialogs/TestPracticeBase TestDialogs/TestPracticeRace TestDialogs/TestText TestHomePage TestProgression TestStats TestUser TestUserSettings TestUtils TestVirtualKeyboard)

cd ${TEST_FOLDER}

for i in ${tests[@]}; do
	cd ${i}
	echo $PWD
	cd ${TEST_FOLDER}
done

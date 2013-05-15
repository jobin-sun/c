#! /bin/bash
# make c run like a script lauguage
# for exmaple:
#   signal line mode:
#	 	bash~$c
#		>>printf("Hello World!\n");
#		//the following is output
#		>>Hello World!
#
#   multi lines mode:
#       bash~$c
#       >>printf("Hello\n");\
#         printf("World\n");
#       //the following is output
#       Hello
#		World
#   
#rm -f .cScriptHistory.log
#touch .cScriptHistory.log
while((1))
do
	echo -n "C>> "
	read -r body
	if [ "$body" == "" ]
	then
		continue
	fi
	if [ "$body" == "q" ]
	then 
		break;
	fi
#	read up < ~/.cScriptUp.key
#	read down< ~/.cScriptDown.key
#	if [ $body == $up ]
#	then
#	read
#	elif [ $body == $down ]
#	then
#	fi
	rm -f .cScriptBody.c
	while echo $body |grep -P "\\\\$" > /dev/null
	do
		echo $body |grep -Po ".*[^\\\\$]" >> .cScriptBody.c
		echo -n "    "
		read -r body
	done
	echo -n $body >> .cScriptBody.c
	if [ ! -f .cScriptContainer.c ]
	then
		cp /usr/local/include/cScriptContainter.c .cScriptContainter.c
	fi
	if gcc -o.cScript .cScriptContainter.c
	then 
		./.cScript
		rm -f .cScript
		rm -f .cScriptBody.c
		rm -f .cScriptContainter.c
	fi
done

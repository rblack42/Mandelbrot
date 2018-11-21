.PHONY:	v_up
v_up:	## Start vagrant VM image
	vagrant up

.PHONY:	v_ssh
v_ssh:	## SSH into vagrant VM
	vagrant ssh

.PHONY:	v_halt
v_halt:	## Stop vagrant VM image
	vagrant halt

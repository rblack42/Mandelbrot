# run provisioning tasks

all:
	ansible-playbook site.yml -vv --ask-become-pass

test:
	ansible-playbook -K site.yml --syntax-check

init:
	./bootstrap.sh



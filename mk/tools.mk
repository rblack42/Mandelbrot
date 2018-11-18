.PHONY: reqs
reqs: ## install python requirements
	pip install -r requirements.txt

.PHONY: venv ## create Python virtual env
venv:	_venv

_venv:
	python3 -m venv _venv


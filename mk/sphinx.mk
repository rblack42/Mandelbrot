.PHONY: html
html:	venv ## run Sphinx to generate html pages
	source _venv/bin/activate && \
	cd rst && \
	sphinx-build -b html -d _build/doctrees . ../docs



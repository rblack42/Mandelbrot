.PHONY: inc-major
inc-major:	## increment major verison number
	@python mk/pyversion.py major

.PHONY: inc-minor
inc-minor:	## increment minor verison number
	@python mk/pyversion.py minor

.PHONY: inc-build
inc-build:	## increment build verison number
	@python mk/pyversion.py build

.PHONY:	version
version: ## display current version number
	@python mk/pyversion.py version

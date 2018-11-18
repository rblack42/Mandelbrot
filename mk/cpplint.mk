LINT		:= cpplint
LINTFLAGS	:= --recursive --quiet

.PHONY: lint
lint:	$(SRCS) $(HDRS) ## Run cpplint over project files
	@$(LINT) $(LINTFLAGS) include lib src


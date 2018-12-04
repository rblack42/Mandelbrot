CXXFLAGS += -std=c++11 -Iinclude

$(TARGET):	$(UOBJS) $(LOBJS) ## build target app
	g++ -o $@ $^ $(LFLAGS)

$(TSTTGT):	$(TOBJS) $(LOBJS) ## build test app
	g++ -o $@ $^ $(LFLAGS)

%.o:	%.cpp
	g++ -c -o $@ $< $(CXXFLAGS)

%.d:	%.cpp
	g++ $(CXXFLAGS) -MM -MT $@ -MF $@ $<

.PHONY: run
run: $(TARGET) ## run application 
	@$(PREFIX)$(TARGET)

.PHONY: test
test: $(TSTTGT) ## run init tests
	@$(PREFIX)$(TSTTGT)

.PHONY: clean
clean: ## delete build artifacts
	$(RM) $(DELFILES) $(TARGET) $(TSTTGT)

-include $(DEPS)

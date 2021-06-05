EXES         := index align
OBJS         := bwa.o \
				kernel.o \
				BWT.o
INCS         := 
deps         := $(OBJS:%.o=%.d)

CFLAGS       := -Wall -Wextra -MMD $(INCS) -std=c17
CXXFLAGS     := -Wall -Wextra -MMD $(INCS) -std=c++17

debug: CFLAGS += -g
debug: CXXFLAGS += -g
release: CFLAGS += -O3 -DNDEBUG
release: CXXFLAGS += -O3 -DNDEBUG


.PHONY: all debug release
all: debug
debug release: $(EXES)

index: index.o $(OBJS)
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@

align: align.o $(OBJS)
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@

.PHONY: clean
clean:
	$(RM) $(EXES) *.d *.o */*.d */*.o

-include $(deps)
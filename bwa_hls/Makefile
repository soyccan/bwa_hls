EXES        := index
OBJS        := \
				index.o \
				../fm_index_ocfnash/openbwt-v1.5/BWT.o
INCS        := \
				-I../fm_index_ocfnash/openbwt-v1.5
deps        := $(OBJS:%.o=%.d)

CFLAGS      := -Wall -Wextra -MMD $(INCS) -std=c17
CXXFLAGS    := -Wall -Wextra -MMD $(INCS) -std=c++17

debug: CFLAGS += -g
debug: CXXFLAGS += -g
release: CFLAGS += -O3
release: CXXFLAGS += -O3


.PHONY: all debug release
all: debug
debug release: $(EXES)

index: index.o $(OBJS)
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@

.PHONY: clean
clean:
	$(RM) $(EXES) *.d *.o

-include $(deps)
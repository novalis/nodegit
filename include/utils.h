#ifndef UTILS_H
#define UTILS_H

#define MAKE_FAST_BUFFER(NG_SLOW_BUFFER, NG_FAST_BUFFER)      \
  Local<Function> NG_JS_BUFFER = Local<Function>::Cast(       \
    Context::GetCurrent()->Global()->Get(                     \
      String::New("Buffer")));                                \
                                                              \
  Handle<Value> NG_JS_ARGS[3] = {                             \
    NG_SLOW_BUFFER->handle_,                                  \
    Integer::New(Buffer::Length(NG_SLOW_BUFFER)),             \
    Integer::New(0)                                           \
  };                                                          \
                                                              \
  NG_FAST_BUFFER = NG_JS_BUFFER->NewInstance(3, NG_JS_ARGS);

#endif

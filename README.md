# hiphop-log
Simple log library for Facebook HHVM

# quick start
```hack
<?hh

$l = new Log();
$l("some notes"); //outputs "08:53:51 some notes"
```

# todo
- [ ] documentation
- [ ] variable logging with `$l($var)`
- [ ] log to a file
- [ ] module support
- [ ] multiplementation
- [ ] log to hipchat/slack/email
  - [ ] hipchat
  - [ ] slack
  - [ ] email
- [ ] API for recieving last `n` log records
- [ ] encryption

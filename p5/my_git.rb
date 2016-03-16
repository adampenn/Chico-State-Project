#!/usr/bin/env ruby

puts "Please enter your commit message:"

message = gets.chomp

`git add --all`
`git commit -m "#{message}"`
`git push`

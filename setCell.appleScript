on run argv
	set sheetName to (item 1 of argv) as string
	set tableName to (item 2 of argv) as string
	set columnName to (item 3 of argv) as string
	set rowNum to (item 4 of argv) as integer
	set cellValue to item 5 of argv
	
	tell application "Numbers Creator Studio"
		tell front document
			tell sheet sheetName
				tell table tableName
					tell column columnName
						tell cell rowNum
							set value to cellValue
						end tell
					end tell
				end tell
			end tell
		end tell
	end tell
end run
require "nokogiri"
require 'fileutils'

def my_abort msg
	puts msg
	puts "Aborting..."
	abort
end

def copy_with_path src, dst
  FileUtils.mkdir_p(File.dirname(dst))
  FileUtils.cp(src, dst)
end

def get_dir_splitter dir
	splitter = ""
	if dir.include? "/"
		splitter = "/"	
	elsif dir.include? "\\"
		splitter = "\\"
	else
		raise "Bad directory #{dir}"
	end

	splitter
end

def remove_last_dir dir
	splitter = get_dir_splitter dir
	arr = dir.split(splitter)
	arr.pop
	arr.join(splitter)
end

def get_last_dir dir
	splitter = get_dir_splitter dir
	dir.split(splitter).last
end

def check_for_errors outputFolder, projectFile
	if not File.exists? projectFile
		my_abort "Project file: #{projectFile} doesn't exist"
	end

	if not Dir.exists? outputFolder
		my_abort "Output folder: #{outputFolder} doesn't exist"
	end
end

def get_content_xml doc, contentFolder
	doc.each do |node|
		if (node.name == 'VirtualDirectory')
			if node.attribute("Name") == contentFolder
				return node.outer_xml
			end
		end
	end

	my_abort "Can't find content folder '#{contentFolder}' in project"
end

def empty_content_dir dir
	FileUtils.rm_r dir
end

def copy_content_folder contentXml, outputDir
	reader = Nokogiri::XML::Reader(contentXml)
	reader.read # Read once for the root tag with content folder
	contentFolder = reader.attribute("Name")
	currCopyDir = "#{outputDir}/#{contentFolder}"

	if Dir.exists? currCopyDir
		empty_content_dir currCopyDir
	end
	
	reader.each do |node|
		if node.name == "VirtualDirectory"
			name = node.attribute("Name")
			if get_last_dir(currCopyDir) == name
				currCopyDir = remove_last_dir(currCopyDir)
			else
				currCopyDir << "/"
				currCopyDir << node.attribute("Name")
			end
		elsif node.name == "File"
			filepath = node.attribute("Name")
			filename = File.basename(filepath)
			copy_with_path(filepath, currCopyDir + "/" + filename)
		end
	end

end

contentFolder = ARGV[0]
outputFolder = ARGV[1]
projectFile = ARGV[2]

if contentFolder == nil
	my_abort "You need to provide content folder"
elsif outputFolder == nil
	my_abort "You need to provide output folder"
elsif projectFile == nil
	my_abort "You need to provide project file"
end

check_for_errors(outputFolder, projectFile)

doc = Nokogiri::XML::Reader(File.read(projectFile))

copy_content_folder(get_content_xml(doc, contentFolder), outputFolder)
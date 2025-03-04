document.addEventListener('DOMContentLoaded', function() {
    // Find all code blocks
    const codeBlocks = document.querySelectorAll('pre.highlight, .highlight pre');
    
    codeBlocks.forEach(function(block) {
      // Check for language class on the block itself
      let lang = '';
      const classes = block.className.split(' ');
      const langClassBlock = classes.find(cls => cls.startsWith('language-'));
      
      if (langClassBlock) {
        lang = langClassBlock.replace('language-', '');
      } else {
        // Check for language class on child code element
        const codeElement = block.querySelector('code');
        if (codeElement) {
          const codeClasses = codeElement.className.split(' ');
          const langClassCode = codeClasses.find(cls => cls.startsWith('language-'));
          if (langClassCode) {
            lang = langClassCode.replace('language-', '');
          }
        }
      }
      
      // If we found a language, set the data attribute
      if (lang) {
        block.setAttribute('data-lang', lang);
      }
      
      // Try to detect language from highlight class
      if (!lang) {
        classes.forEach(function(cls) {
          if (cls.startsWith('highlight-')) {
            lang = cls.replace('highlight-', '');
            block.setAttribute('data-lang', lang);
          }
        });
      }
      
      // Check for commonly used language classes
      if (!lang) {
        // Check for Rouge style classes (language-*)
        for (const cls of classes) {
          if (cls === 'cpp' || cls === 'python' || cls === 'javascript' || cls === 'ruby' || 
              cls === 'java' || cls === 'html' || cls === 'css' || cls === 'bash') {
            block.setAttribute('data-lang', cls);
            break;
          }
        }
      }
    });
  });
  
document.addEventListener('DOMContentLoaded', function() {
    // Find all code blocks
    const codeBlocks = document.querySelectorAll('pre.highlight');
    
    codeBlocks.forEach(function(block) {
      // Try to determine language from class
      const classes = block.className.split(' ');
      const langClass = classes.find(cls => cls.startsWith('language-'));
      
      if (langClass) {
        const lang = langClass.replace('language-', '');
        block.setAttribute('data-lang', lang);
      }
    });

    codeBlocks.forEach(function(block) {
      // Create the fold button
      const foldButton = document.createElement('button');
      foldButton.className = 'code-fold-btn';
      foldButton.textContent = '−';
      foldButton.title = 'Fold code';
      
      // Get the code element
      const codeElement = block.querySelector('code');
      if (!codeElement) return;
      
      // Get the first line
      const lines = codeElement.innerHTML.split('\n');
      const firstLine = lines[0];
      
      // Add the button to the code block
      block.prepend(foldButton);
      
      // Add click event
      foldButton.addEventListener('click', function() {
        if (block.classList.contains('folded')) {
          // Unfold
          block.classList.remove('folded');
          foldButton.textContent = '−';
          foldButton.title = 'Fold code';
          codeElement.innerHTML = lines.join('\n');
        } else {
          // Fold
          block.classList.add('folded');
          foldButton.textContent = '+';
          foldButton.title = 'Unfold code';
          codeElement.innerHTML = firstLine;
          // codeElement.innerHTML = firstLine + '\n...';
        }
      });
    });
  });
  